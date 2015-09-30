//==========================================================
// FreeMotion_Engine.sce, v1.4 (BIRDY_TS: Trajectory solver)
//==========================================================
// date : 03-Feb-2015
// Ref: GSE-001
// CL=1
// by	Boris SEGRET from v1.2
//	+Audrey PORQUET before v1.2
//
// Numerical integration engine
// 	- ACCJ2Sun(..)
// 	- ACCJ2Mars(..)
// 	- ACCJ2Terre(..)
//  - fct(..)
//  - integrale(..)
//

//function which computes the J2 term of the acceleration for the Sun 
function [apJ2Sun]=ACCJ2Sun(ricrs,vicrs,tcjdtt,ttref)
    [rbcfSun,vbcfSun,jicrs2bcfSun,Micrs2bcfSun]=ICRS2BCFSun(ricrs,vicrs,tcjdtt,ttref)
    apJ2eqSun=CL_fo_zonHarmAcc(rbcfSun,2,er=eqRadSun,mu=muSun,j1jn=[0;J2Sun])
    apJ2Sun=Micrs2bcfSun'*apJ2eqSun;
endfunction

//function which computes the J2 term of the acceleration for Mars
function [apJ2Mars]=ACCJ2Mars(ricrs,vicrs,posMarsicrs,velMarsicrs,tcjdtt,ttref)
    [rbcfMars,vbcfMars,jicrs2bcfMars,Micrs2bcfMars]=ICRS2BCFMars(ricrs,vicrs,posMarsicrs,velMarsicrs,tcjdtt,ttref)
    apJ2eqMars=CL_fo_zonHarmAcc(rbcfMars,2,er=eqRadMars,mu=muMars,j1jn=[0;J2Mars])
    apJ2Mars=Micrs2bcfMars'*apJ2eqMars;
endfunction

//function which computes the J2 term of the acceleration for the Earth
function [apJ2Terre]=ACCJ2Terre(ricrs,vicrs,posTerreicrs,velTerreicrs,tcjdtt,ttref)
[recfTerre,vecfTerre,jicrs2ecfTerre,Micrs2ecfTerre]=ICRS2ECFTerre(ricrs,vicrs,posTerreicrs,velTerreicrs,tcjdtt,ttref)
    apJ2eqTerre=CL_fo_zonHarmAcc(recfTerre,2,er=eqRadEarth,mu=muEarth)
    apJ2Terre=Micrs2ecfTerre'*apJ2eqTerre;
endfunction
//=========================================================

function [yp] = fct(t,y,dat)
    //_bs_
    // Here is the Celestial Dynamics model => make it clear, testable, maintanable
    //  already computed (same dates?) in main program!!! => to be optimized or memory to be cleaned
    //_bs_
   [pos_mars_i_eod,vel_mars_i_eod]= CL_eph_planet("Mars", dat , model="full");
   [pos_earth_i_eod,vel_earth_i_eod]= CL_eph_planet("Earth", dat , model="full");
	//  changement de repere pour les ephemerides : passage du EOD a ICRS :
   [pos_mars_i_icrs,vel_mars_i_icrs]=CL_fr_convert("EOD","ICRS", dat, pos_mars_i_eod, vel_mars_i_eod);
   [pos_earth_i_icrs,vel_earth_i_icrs]=CL_fr_convert("EOD","ICRS", dat, pos_earth_i_eod, vel_earth_i_eod);

    pos = y(1:3,:); 
    vel = y(4:6,:); 
    yp = zeros(y);  
    yp(1:3,:) = vel;
    //_bs_
    //  1. Here are 3 objects (submodels) taken into account => Make the writing easy to read for N submodels
    //  2. As well submodels for the Radiation pressure and other disturbances shall be added in future upgrades
    //  3. Compute the relevant time sampling for all the submodels
    //      - it depends on the SOI and on the period of each submodel
    //      - the lowest time sampling shall be injected in the main Runge Kutta algorithm
    //  4. Consider 2 modes if the model is CPU consuming
    //      - Mode "low resolution": compute with only Earth, Mars, Sun
    //      - Mode "high resolution": compute with all submodels (good way to produce an "initial guess")
    //_bs_
    AccSun=ACCJ2Sun(pos,vel,dat,ttref=%CL_TT_TREF);
    AccMars=ACCJ2Mars(pos,vel,pos_mars_i_icrs,vel_mars_i_icrs,dat,ttref=%CL_TT_TREF);
    AccEarth=ACCJ2Terre(pos,vel,pos_earth_i_icrs,vel_earth_i_icrs,dat,ttref=%CL_TT_TREF);
    
    yp(4:6,:) = CL_fo_centralAcc(pos,mu=muSun)+AccSun+CL_fo_centralAcc(pos-pos_mars_i_icrs,mu=muMars)+AccMars+CL_fo_centralAcc(pos-pos_earth_i_icrs,mu=muEarth)+AccEarth;
endfunction
//=========================================================


function [X_eclip, V_eclip, datebis, r_SC, r_TC, r_MC, r_ST, r_SM] = ...
  integrale(dat, pos, vit)
//_bs_ Attempt for a documentation:
// Runge_Kutta_4 algorithm
// I/ dat, pos, vit: UTC start date, start position and start velocity of the numerical integration
// O/   X_eclip, V_eclip: (1x npas) Positions and Velocities in Ecliptic frame for "npas" time steps
//      datebis
//      r_SC, r_TC, r_MC: (1x npas) distances to CubeSat from Sun, Earth, Mars
//      r_ST, r_SM: (1x npas) distance from Sun to Earth, Mars
//_bs_


//Initial conditions
datebis(1) = CL_dat_scaleConvert("UTC","TT",dat); //date of departure of the numerical integration in MJD/1950.0
[ricrs, vicrs, jeme2icrs] = CL_fr_convert("EME2000", "ICRS", datebis(1), pos, vit);
X(1:3,1)=ricrs;
X(4:6,1)=vicrs;
t(1)=datebis(1)*86400;//date in seconds

for i=2:npas;
//_bs_ attention: emploi d'une variable globale
//_bs_ DEBUG:
	if (i/1000.==floor(i/1000)) then
		[fd,err]=mopen(longLog, 'at'); mfprintf(fd, '%d\n  ', i); err = mclose(fd);
	elseif (i/10.==floor(i/10)) then
		[fd,err]=mopen(longLog, 'at'); mfprintf(fd, '.'); err = mclose(fd);
	end
//_bs_

    datebis(i)=datebis(1)+(i-1)*hpas/86400; //date in modified julian date from 1950.0
    t(i)=datebis(i)*86400; //date in seconds
    dt=t(i)-t(i-1); //time interval (seconds)

    p1 = fct(i-1,      X(1:6,i-1),                datebis(i-1)); //function p1 of RK4
    p2 = fct(i-1+dt/2, X(1:6,i-1)+dt/2*p1(1:6,1), datebis(i-1)+dt/(2*86400)); //function p2 of RK4
    p3 = fct(i-1+dt/2, X(1:6,i-1)+dt/2*p2(1:6,1), datebis(i-1)+dt/(2*86400)); //function p3 of RK4
    p4 = fct(i-1+dt,   X(1:6,i-1)+dt*p3(1:6,1),   datebis(i-1)+dt./86400); //function p4 of RK4
    X(1:6,i) = X(1:6,i-1) + (hpas/6)*(p1(1:6,1)+2*p2(1:6,1)+2*p3(1:6,1)+p4(1:6,1));
    //Gives the position and the velocity of the next point thanks to the last point and to p1, p2, p3, p4.
end

//--------------------------------------------------------------------------------------------------------
// CubeSat's ephemeris
[X_eod, V_eod] = CL_fr_convert("ICRS","EOD", datebis', X(1:3,:), X(4:6,:));
[X_eme, V_eme] = CL_fr_convert("EOD","EME2000", datebis', X_eod, V_eod);
X_eclip=Meme2eclip*X_eme;
V_eclip=Meme2eclip*V_eme;
//_bs_ 3 frame conversions (ICRS>EOD>EME2000>ECLIPTIC)!!! is this the best way?!

r_SC=CL_norm(X_eclip); //Radius Sun-CubeSat (in meter)

//--------------------------------------------------------------------------------------------------------
// Earth's ephemeris (position in x,y,z, velocity along x,y,z) for each dates (EOD frame) :
[pos_terre_eod, vel_terre_eod] = CL_eph_planet("Earth", datebis' ,model="full");
// in J2000 equatorial : frame change for ephemeris : from EOD to EME2000 (=J2000 equatorial) :
[pos_terre_eme, vel_terre_eme] = CL_fr_convert("EOD","EME2000",datebis',pos_terre_eod,vel_terre_eod);
// in J2000 ecliptic : frame change for ephemeris: from EME2000 to J2000 ecliptic (position in m, velocity in m/s)
pos_terre_eclip = Meme2eclip*pos_terre_eme;
r_ST = CL_norm(pos_terre_eclip);

//--------------------------------------------------------------------------------------------------------
// Mars' ephemeris (position in x,y,z, velocity along x,y,z) for each dates (EOD frame) :
[pos_mars_eod,vel_mars_eod] = CL_eph_planet("Mars", datebis', model="full");
// in J2000 equatorial : frame change for ephemeris : from EOD to EME2000 (=J2000 equatorial) :
[pos_mars_eme,vel_mars_eme] = CL_fr_convert("EOD", "EME2000", datebis',pos_mars_eod,vel_mars_eod);
// in J2000 ecliptic : frame change for ephemeris: from EME2000 to J2000 ecliptic (position in m, velocity in m/s)
pos_mars_eclip = Meme2eclip*pos_mars_eme;
r_SM = CL_norm(pos_mars_eclip);

//--------------------------------------------------------------------------------------------------------
//Computation of the distances to CubeSat
r_TC = CL_norm(X_eclip-pos_terre_eclip);
r_MC = CL_norm(X_eclip-pos_mars_eclip);

//_bs_ DEBUG
[dMC, iMC] = min(r_MC);
[fd,err]=mopen(longLog, 'at');
mfprintf(fd, '  rSC=%.4fAU, rTC=%.4fAU, rMC =%.8fAU =(SOI+)%.0fkm =(rMars+)%.0fkm\n', r_SC(iMC)/%CL_au, r_TC(iMC)/%CL_au, dMC/%CL_au, (dMC-rsoiMars)/1000., (dMC/1000.-3600.));
err = mclose(fd);
//_bs_
endfunction
//=========================================================

