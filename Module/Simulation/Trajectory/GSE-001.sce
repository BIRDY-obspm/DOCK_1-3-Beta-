//=========================================================
// BIRDY_TS: Trajectory solver v6.3 : from Earth to Mars 
//=========================================================
// date : 07-Feb-2015
// Ref: GSE-001, see documentation with this reference
// CL=1
// by	Boris SEGRET from v6.2
//		+ Audrey PORQUET from v0 to v6 (26/08/2014)
//		(previous name: "BIRDY-GSE-006.sce")

// The software "BIRDY_TS" (ref. GSE-001.sce v6.3) requires CelestLab and several .sce files in the same folder:
//	GSE-001_inputs.sce,	v1.1 (template)
//      <host_trajectory> given in GSE-001_inputs.sce (ex.: "GL-01_sun_58122.xyzv")
// ...and these files:
//	CelestLab is the CNES' SciLab library (routines are prefixed "CL_")
//	GSE-001_settings.sce,	v1.3
//	GSE-001_functions.sce,	v1.3
//	FreeMotion_Engine.sce,	v1.4
//	GSE-001_results.sce,	v1.0
//	GSE-001_outputs.sce,	v1.0
// ...and a bash file to launch several jobs of GSE-001 from the command line:
//	BIRDY_TS_batch,		v0.1
//
// Outputs: CubeSat location = f(t) (Earth-Mars trajectory), Earth-CubeSat, Mars-CubeSat, Sun-CubeSat distances =f(t)
//
// BIRDY_TS computes a new Earth-Mars trajectory from the input with a Runge-Kutta algorithm:
//	1.Initial Delta-V from Lambert Problem solutions for 1 jettisoning date and several arrival dates near Mars
//	2.Numerical integration with the selected Delta-V
//	(3).Quantifying "performance criteria" for this jettisoning date (minimum distance to Mars)
//	(4).Loop for another jettisoning date

a=getdate(); mprintf('Starting (yyy-mm-ddThh:mm): %d-%d-%dT%d:%d\n', a(1), a(2), a(6), a(7), a(8)); tic(); timer;
exec('GSE-001_settings.sce');
movefile('GSE-001_inputs.sce', 'GSE-001_inputs');

//==========================================================================================
//read the host trajectory 
//_bs_ !!! Misuse of the memory: the entire Host_traj is read while only the beginning is useful. 
//         Moreover the memory is not cleared of these data after reading !!!

[Z]=read(Host_traj,-1,7);
//extraction des donnees du fichier
dZcjd=CL_dat_convert("jd","cjd", Z(:,1)'); // 1*N, Modified Julian date
position_Z(1,:)=Z(:,2)'*bs_units; //en m
position_Z(2,:)=Z(:,3)'*bs_units; //en m
position_Z(3,:)=Z(:,4)'*bs_units; //en m
vitesse_Z(1,:)=Z(:,5)'*bs_units; //en m/s
vitesse_Z(2,:)=Z(:,6)'*bs_units; //en m/s
vitesse_Z(3,:)=Z(:,7)'*bs_units; //en m/s

[lig,col]=size(dZcjd);

//===========================================================================================
//ephemeris Mars, then Earth
  [pos_mars_i_eod,vel_mars_i_eod] = CL_eph_planet("Mars", dZcjd, model="full");
//Dans J2000 equatorial: changement de repere pour les ephemerides: passage du EOD au EME2000 (=J2000 equatorial) :
  [pos_mars_i_eme,vel_mars_i_eme] = CL_fr_convert("EOD","EME2000", dZcjd, pos_mars_i_eod, vel_mars_i_eod);
//Dans J2000 écliptique: changement de repere pour les ephemerides: passage du EME2000 au J2000 ecliptique
//(Meme2eclip: matrice de rotation, dans sous-programme)
  pos_mars_i_eclip = Meme2eclip*pos_mars_i_eme;
  vel_mars_i_eclip = Meme2eclip*vel_mars_i_eme;
  
  [pos_earth_i_eod,vel_earth_i_eod] = CL_eph_planet("Earth", dZcjd, model="full");
  [pos_earth_i_eme,vel_earth_i_eme] = CL_fr_convert("EOD","EME2000", dZcjd, pos_earth_i_eod, vel_earth_i_eod);
  pos_earth_i_eclip=Meme2eclip*pos_earth_i_eme;
  vel_earth_i_eclip=Meme2eclip*vel_earth_i_eme;
//-----------------------------------------------
//_bs_
//	here is some code to characterize the entrances and exits of the SOIs
//	It should bette analyze the host trajectory in more details to set the algorithm key parameters
//	- "arrival dates": the best arrival date to arrive as close of Mars as possible (attempt herein)
//	-...
//_bs_

D1 = CL_norm(pos_earth_i_eclip(:,1:(floor(col/2)))); //_bs_ pour la 1ere moitie de la duree de la traj
D2 = CL_norm(pos_earth_i_eclip(:,(floor(col/2)+1):col)); //_bs_ pour la 2eme moitie de la duree de la traj
D3 = CL_norm(pos_mars_i_eclip);  //_bs_ pour toute la duree de la traj
rsoiTerre1 = CL_ip_sphereInfluence(muEarth,muSun,D1); 
rsoiTerre2 = CL_ip_sphereInfluence(muEarth,muSun,D2); 
rsoiMars = CL_ip_sphereInfluence(muMars,muSun,D3);
rTC1=CL_norm(position_Z(:,1:floor(col/2))-pos_earth_i_eclip(:,1:floor(col/2)));
rTC2=CL_norm(position_Z(:,(floor(col/2)+1):col)-pos_earth_i_eclip(:,(floor(col/2)+1):col));
rMC=CL_norm(position_Z-pos_mars_i_eclip);

indice1 = find(rTC1 < rsoiTerre1); //Last indice1 = point of the output of the Earth's Sphere Of Influence (Departure from the Earth) (host mission)
indice2 = find(rTC2 < rsoiTerre2); //First indice2 = point of the enter in the Earth's Sphere Of Influence (Arrival to the Earth) (host mission)
indice3 = find(rMC < rsoiMars);    //All indice3 are in the Sphere Of Influence of Mars (host mission)
[l1,c1]=size(indice1); 
[l3,c3]=size(indice3);

//=====================================================================================
//plot of the host mission trajectory with the Mars orbit and the Earth orbit
//=====================================================================================
f = scf(0);
//trace des ephemerides de mars de date1 a date2
  param3d(0,0,0); // Sun at the center
  h = CL_g_select(gce(), "Polyline"); // h=gce() pourrait marcher mais risque que ça ne marche pas si structure complexe
  h.line_mode = "off"; 
  h.mark_mode = "on"; 
  h.mark_style = 0; // round mark
  h.mark_background = color("orange");
  h.mark_foreground = color("orange");
  h.mark_size_unit = "point"; 
 h.mark_size = 15;

//trace de la trajectoire du satellite de date1 a date2 (attention peuvent etre different de la date de depart et de la date d'arrivee)
param3d(position_Z(1,:)/%CL_au, position_Z(2,:)/%CL_au, position_Z(3,:)/%CL_au);
h = CL_g_select(gce(),"Polyline");
h.thickness = 2;
h.foreground = color("black");
 
//param3d(position_Z(1,col/3)/%CL_au,  position_Z(2,col/3)/%CL_au, position_Z(3,col/3)/%CL_au);
//_bs_ Mieux vaut montrer un point (de la traj Host) à la moitié du chemin aller (pas forcément col/2)
//	=> 'bs_blackdot' defined in the settings
param3d(position_Z(1,bs_blackdot)/%CL_au,  position_Z(2,bs_blackdot)/%CL_au, position_Z(3,bs_blackdot)/%CL_au);
h = CL_g_select(gce(), "Polyline"); 
  h.line_mode = "off"; 
  h.mark_mode = "on"; 
  h.mark_style = 11; // square mark
  h.mark_background = color("black");
  h.mark_foreground = color("black");
  h.mark_size_unit = "point"; 
 h.mark_size = 10;
 
param3d(pos_earth_i_eclip(1,:)/%CL_au, pos_earth_i_eclip(2,:)/%CL_au, pos_earth_i_eclip(3,:)/%CL_au);
h = CL_g_select(gce(),"Polyline");
h.thickness = 2;
h.foreground = color("blue");

  param3d(pos_earth_i_eclip(1,1)/%CL_au,pos_earth_i_eclip(2,1)/%CL_au,pos_earth_i_eclip(3,1)/%CL_au); // Terre at Departure
  h = CL_g_select(gce(), "Polyline");
  h.line_mode = "off"; 
  h.mark_mode = "on"; 
  h.mark_style = 0; // round mark
  h.mark_background = color("blue");
  h.mark_foreground = color("blue");
  h.mark_size_unit = "point"; 
 h.mark_size = 10;

param3d(pos_mars_i_eclip(1,:)/%CL_au, pos_mars_i_eclip(2,:)/%CL_au, pos_mars_i_eclip(3,:)/%CL_au);
h = CL_g_select(gce(),"Polyline");
h.thickness = 2;
h.foreground = color("red");

  param3d(pos_mars_i_eclip(1,col)/%CL_au,pos_mars_i_eclip(2,col)/%CL_au,pos_mars_i_eclip(3,col)/%CL_au); // Mars at end of Host traj
  //_bs_
  //	Showing Mars at various key positions (at Earth departure, at flyby, at Earth back)
  //	would be smarter than only at the last point of the host trajectory
  //_bs_
  h = CL_g_select(gce(), "Polyline");
  h.line_mode = "off"; 
  h.mark_mode = "on"; 
  h.mark_style = 0; // round mark
  h.mark_background = color("red");
  h.mark_foreground = color("red");
  h.mark_size_unit = "point"; 
 h.mark_size = 10;

//_bs_ Monitoring of program's behaviour in <longLog>. Caution: open & close each time!
[fd,err]=mopen(longLog, 'at'); mfprintf(fd, '\n=== DEBUG ===\n'); err = mclose(fd);
[fd,err]=mopen(longLog, 'at'); mfprintf(fd, 'Traj.lue: %f %f %f %f %f %f %f \n', Z(1,:)); err = mclose(fd);

for k=kjettison:kjettison
// One single date is considered only. The minimum DeltaV to reach Mars from this date is computed
// this 'indice1(1,c1)+k' complicated index is kept as previously but must be cleaned later

	//_bs_ carefully check Meme2eclip consistency (is Earth's position taken into account?)
	position_Z_eme = (Meme2eclip)'*(position_Z(:,indice1(1,c1)+k));
	vitesse_Z_eme  = (Meme2eclip)'*(vitesse_Z(:,indice1(1,c1)+k)+deltaV);
	datecjdTTd     = CL_dat_scaleConvert("UTC","TT",dZcjd(:,indice1(1,c1)+k));

	// 	1st pass, search for Arrival Date to arrive at Mars with the minimum Delta-V
	//  	=> CubeSat's velocity = (vdep - Host's velocity)
	clear arrivalDates;
	arrivalDates = datecjdTTd + bs_nominalArr + [-bs_nbDatesArr:bs_nbDatesArr];
	vdep = arrivals_Mars(datecjdTTd, position_Z(:,indice1(1,c1)+k), arrivalDates); // vdep: 3xN vectors
	vref = repmat(vitesse_Z(:,indice1(1,c1)+k), 1, length(arrivalDates));
	dvc = CL_norm(vdep-vref);
	[dvm, ard] = min(dvc);
	//disp("check dvc, dvm, ard"); pause;
	//_bs_ DEBUG:
	jarr = datecjdTTd +bs_nominalArr -bs_nbDatesArr +ard-1.;
	[fd,err]=mopen(longLog, 'at'); mfprintf(fd, 'Lambert Pb Call, 1st pass, dv=%.2fm/s on %.1fj\n', dvm, jarr); err = mclose(fd);
	//_bs_

	// 	2nd pass, search for Delta-V to arrive within 3 days before or after the most energy saving arrival date
	//  	=> focus around the minimum of CL_norm(CubeSat's velocity) : Bisection method, that requires
	//	the slope df/dv of the function 'distance-to-Mars' in function of the departure velocity
	clear arrivalDates;
	arrivalDates = datecjdTTd +bs_nominalArr -bs_nbDatesArr +ard-1 + [-PbLambertAccuracy:1/24.:PbLambertAccuracy];
	vdep = arrivals_Mars(datecjdTTd, position_Z(:,indice1(1,c1)+k), arrivalDates); // vdep: 3xN vectors
	vref = repmat(vitesse_Z(:,indice1(1,c1)+k), 1, length(arrivalDates));
	dvc = CL_norm(vdep-vref);
	[dvm, arh] = min(dvc);
	//_bs_ DEBUG:
	jarr = datecjdTTd +bs_nominalArr -bs_nbDatesArr +ard-1.-PbLambertAccuracy +(arh-1.)/24.;
	[fd,err]=mopen(longLog, 'at'); mfprintf(fd, 'Lambert Pb Call, 2nd pass, dv=%.2fm/s on %.1fj\n', dvm, jarr); err = mclose(fd);
	//disp("check dvc, dvm, arh"); pause;

	// Bisection method ("dichotomy" in French) initialisation
	//
	// Search for the minimum of f(v)=min(distance-to-Mars), then the zero of df/dv starting negative
	// An approximate value of df/dv is given by 2 calculations at delta-V and (delta-V +d2v)
	// d2V : accuracy of the delat-V provided by the electric propulsion: ~1H => 1/20 de 1m/s
	// The search for a minimum should be made before or after 0.01% of the Min delta-V value
	// found above (vdep(:,arh))
	//
	vdep0 = vdep(:,arh); // here we keep vdep as the 3x1 vector that is the best solution of the Lambert Problem
	vref0 = vref(:,arh); // same as vitesse_Z(:,indice1(1,c1)+k); velocity at the departure
	d2i = d2v/CL_norm(vdep0);
	
	//_bs_ DEBUG:
	[fd,err]=mopen(longLog, 'at');
    	mfprintf(fd, '  (Init.Bisect.meth., ii=100%%, dv=%.3f m/s)\n  ', CL_norm(vdep0-vref0));
    	err = mclose(fd);
	//_bs_

	vdep_eme = (Meme2eclip)'*vdep0;
	// "deltaV" initialized at [0,0,0]
	[datesdepJD, DeltaVLambert, minr_MC, minr_TC] = DVLambert( ...
            dZcjd(:,indice1(1,c1)+k), vdep_eme, position_Z_eme, vitesse_Z(:,indice1(1,c1)+k), deltaV);
	dii = minr_MC;

	vdep_eme = (Meme2eclip)'*(1+d2i)*vdep0;
	[datesdepJD, DeltaVLambert, minr_MC, minr_TC] = DVLambert( ...
            dZcjd(:,indice1(1,c1)+k), vdep_eme, position_Z_eme, vitesse_Z(:,indice1(1,c1)+k), deltaV);
	d2ii = minr_MC-dii; // slope
	dinf=0.; dsup=0.;
	if (d2ii < 0.) then
		iinf = 1.; isup=1.0001; ii=isup;
		dinf = dii;
	else
		isup = 1.; iinf=0.9999; ii=iinf;
		dsup = dii;
	end

	vdep_eme = (Meme2eclip)'*ii*vdep0;
	dvm = CL_norm(ii*vdep0-vref0);

	//_bs_ DEBUG:
	[fd,err]=mopen(longLog, 'at');
	mfprintf(fd, '  (Init.Bisect.meth., (ii-1)=%.6f%%, dv=%.3f m/s)\n  ', (ii-1.)*100., dvm);
	err = mclose(fd);
	//_bs_

	[datesdepJD, DeltaVLambert, minr_MC, minr_TC] = DVLambert( ...
            dZcjd(:,indice1(1,c1)+k), vdep_eme, position_Z_eme, vitesse_Z(:,indice1(1,c1)+k), deltaV);
	dii=minr_MC;
	vdep_eme = (Meme2eclip)'*(ii+d2i)*vdep0;
	[datesdepJD, DeltaVLambert, minr_MC, minr_TC] = DVLambert( ...
       dZcjd(:,indice1(1,c1)+k), vdep_eme, position_Z_eme, vitesse_Z(:,indice1(1,c1)+k), deltaV);

	//_bs_ DEBUG:
	if ((minr_MC-dii)*d2ii>0) then
		[fd,err]=mopen(longLog, 'at');
		mfprintf(fd, '  *** Bisect.meth initialization failed ***\n');
		mfprintf(fd, '  *** same sign (+/-) of slope at both boundaries: %.0fkm %.0fkm\n', d2ii/1000., (minr_MC-dii)/1000.);
		mfprintf(fd, '  *** solution will not be optimized');
		err = mclose(fd);
	end
	//_bs_

    nloop=0;
    while and([(isup-iinf)>(4.*d2i) nloop<(PbLambertAccuracy*24)]) do
        nloop = nloop+1;
        ii = ((iinf+isup)/2.); // optimization: dividing the section according to the last computed slopes
    	vdep_eme = (Meme2eclip)'*ii*vdep0;
        dvm = CL_norm(ii*vdep0-vref0);
        //_bs_ DEBUG:
		[fd,err]=mopen(longLog, 'at');
        mfprintf(fd, '  (RK4 dMC<%.8f => (ii-1)=%.6f%%, dv=%.3fm/s, npas=%d)\n  ', min([dinf dsup])/%CL_au, (ii-1.)*100., dvm, npas);
        err = mclose(fd);
        //_bs_
        [datesdepJD, DeltaVLambert, minr_MC, minr_TC] = DVLambert( ...
                dZcjd(:,indice1(1,c1)+k), vdep_eme, position_Z_eme, vitesse_Z(:,indice1(1,c1)+k), deltaV);
        dii = minr_MC;

    	vdep_eme = (Meme2eclip)'*(ii+d2i)*vdep0;
        [datesdepJD, DeltaVLambert, minr_MC, minr_TC] = DVLambert( ...
           dZcjd(:,indice1(1,c1)+k), vdep_eme, position_Z_eme, vitesse_Z(:,indice1(1,c1)+k), deltaV);
        d2ii = minr_MC-dii;

        if (d2ii < 0.) then
            iinf = ii;
            dinf = dii;
        else
            isup = ii;
            dsup = dii;
        end
    end

	//_bs_
	// below is very complicated and risky for id = the "first" index with minr_MC
	//id = find(minr_MC==min(minr_MC));
	//DeltaVLambert_eme = (Meme2eclip)'*(DeltaVLambert(:,id(1,1)));
	ii = ((iinf+isup)/2.);
	vdep_eme = (Meme2eclip)'*ii*vdep0;
	dvm = CL_norm(ii*vdep0-vref0);

	//_bs_ DEBUG:
	[fd,err]=mopen(longLog, 'at');
    mfprintf(fd, 'Exit of Bisect.Meth. => dinf=%d, dsup=%d, (ii-1)=%.6f%%\n', dinf, dsup, ii*100.);
    mfprintf(fd, 'Call of final Runge-Kutta (k=%d, npas=%d)\n  ', k, npas);
    err = mclose(fd);
    //_bs_
	//[X_eclip, V_eclip, datebis, r_SC, r_TC, r_MC, r_ST, r_SM] = ...
	//	integrale(dZcjd(:,indice1(1,c1)+k), position_Z_eme, vitesse_Z_eme+DeltaVLambert_eme);
	[X_eclip, V_eclip, datebis, r_SC, r_TC, r_MC, r_ST, r_SM] = ...
		integrale(dZcjd(:,indice1(1,c1)+k), position_Z_eme, vdep_eme);

	datesJD = CL_dat_convert("cjd","jd",datebis'); 
	//	B = datesJD(1,:)';
	//	B(:,2) = X_eclip(1,:)'/bs_units; //position along x in km
	//	B(:,3) = X_eclip(2,:)'/bs_units; //position along y in km
	//	B(:,4) = X_eclip(3,:)'/bs_units; //position along z in km
	//	B(:,5) = V_eclip(1,:)'; //velocity along x in m/s
	//	B(:,6) = V_eclip(2,:)'; //velocity along y in m/s
	//	B(:,7) = V_eclip(3,:)'; //velocity along z in m/s
	//	B(:,8) = r_SC(1,:)'/bs_units; //distance in km

	C = datesJD(1,:)';
	//_bs_ quelle differences pour C(:,1..8) avec B(:,1..8) ?!?
	C(:,2)  = X_eclip(1,:)'/bs_units; //position along x in km
	C(:,3)  = X_eclip(2,:)'/bs_units; //position along y in km
	C(:,4)  = X_eclip(3,:)'/bs_units; //position along z in km
	C(:,5)  = V_eclip(1,:)'; //velocity along x in m/s
	C(:,6)  = V_eclip(2,:)'; //velocity along y in m/s
	C(:,7)  = V_eclip(3,:)'; //velocity along z in m/s
	C(:,8)  = r_SC(1,:)'/bs_units; //distance in km
	C(:,9)  = r_TC(1,:)'/bs_units; //distance in km
	C(:,10) = r_MC(1,:)'/bs_units; //distance in km
	C(:,11) = r_ST(1,:)'/bs_units; //distance in km
	C(:,12) = r_SM(1,:)'/bs_units; //distance in km

	//_bs_  ecriture d'un critere mais n'importe ou (!!)
	//	crit(...) est enregistre dans outputcrits puis plot de (crit(:,2), crit(:,3)) en finale
	//	ces 3 valeurs semblent être 3 matrices (1,1)
	//crit((indice1(1,c1)+k),1) = datesdepJD(:,id(1,1));
	//crit((indice1(1,c1)+k),2) = minr_MC(:,id(1,1));
	//crit((indice1(1,c1)+k),3) = CL_norm(DeltaVLambert(:,id(1,1)));
    [criteria(1) arh] = min(r_MC);
    criteria(2) = arh;
    criteria(3) = datesdepJD;
    criteria(4) = dvm;
    criteria(5:7) = ii*vdep0;

	//_bs_ DEBUG:
	[fd,err]=mopen(longLog, 'at');
    mfprintf(fd, 'Ecriture fichiers ..._%s...xyzv puis MàJ graphes\n', string(indice1(1,c1)+k));
    err = mclose(fd);
	//_bs_ ATTENTION A ECRASEMENT DES FICHIERS PRECEDENTS (nommage à 0.1 jour!)
	//_bs_ risque majeur de confusion dans les fichiers
	//	fd2 = mopen(outputfile,'wt'); //ouvrir le fichier test_integration_num2.xyzv dans le repertoire output2, acces autorise pour écriture "wt"
	//	mfprintf(fd2,'%.17f\t%.17f\t%.17f\t%.17f\t%.17f\t%.17f\t%.17f\t%.17f\n',B); //ecrire B dans le fichier 
	//	mclose(fd2); //fermer le fichier

	outputfile2=outputfiles+string(indice1(1,c1)+k);
	fd = mopen(outputfile2+".xyzv",'wt');
	mfprintf(fd,'%.17f\t%.17f\t%.17f\t%.17f\t%.17f\t%.17f\t%.17f\t%.17f\t%.17f\t%.17f\t%.17f\t%.17f\n', C);
	mclose(fd);

	// Pour éphémérides des planètes il faudra un nom mieux que: outputfiles+string(datesdepJD(:,id(1,1)))+"_ephjup.xyzv"
	// MANDATORY: also track the (Host,CubeSat) distance
	// below are two subprograms (not functions) called in the main loop of GSE-001
	exec('GSE-001_results.sce');
	exec('GSE-001_outputs.sce');
end

//_bs_ DEBUG:
[fd,err]=mopen(longLog, 'at'); mfprintf(fd, 'Sortie boucle principale, ecriture Perfos <=======\n'); err = mclose(fd);

//fd = mopen(outputcrits,'wt');
//mfprintf(fd,'%.17f\t%.17f\t%.17f\n', crit);
fd = mopen(outputcrits,'at');
mfprintf(fd,'%.17f\t%.17f\t%.17f\t%.17f\t%.17f\t%.17f\t%.17f\n', criteria');
mclose(fd);

//[Cr]=read(outputcrits,-1,3); //read all the file outputcrits that contains 3 columns
//extraction of the file's data
//d_jetti=Cr(:,1); //dates
//rMCmin=Cr(:,2);//min of minrMC
//dv=Cr(:,3);//deltav
//f = scf(14);
//a=gca();
//a.title
//type(a.title)
//plot2d(d_jetti,dv,-1);
//xtitle("Performance criterion ","Date of jettisioning from the host mission (in julian day)","DeltaV (m/s)")

a=getdate(); mprintf('Ending (yyy-mm-ddThh:mm): %d-%d-%dT%d:%d\n', a(1), a(2), a(6), a(7), a(8));
t= toc(); tcpu = timer();
mprintf('CPU use: Total time %.1fmn, CPU (Nb.of processor cycles) %.3f', t/60., tcpu);


