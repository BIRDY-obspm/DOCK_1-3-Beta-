//==========================================================
// GSE-001_functions.sce, v1.3 (BIRDY_TS: Trajectory solver)
//==========================================================
// date : 24-Jan-2015
// Ref: GSE-001
// CL=1
// by	Boris SEGRET from v1.2
//	+ Audrey PORQUET before v1.2
//
// Contains the functions for GSE-001, including the call to the Numerical integrations:
//	(call to FreeMotion_Engine.sce)
//	DVLambert(..)
//	arrivals_Mars(..)
// 	EOD2ICRS(..)
// 	ICRS2BCFSun(..)
// 	ICRS2BCFMars(..)
// 	ICRS2ECFTerre(..)
//

// Function declarations for the Numerical integration engine
//
exec('FreeMotion_Engine.sce');
//===============================================================================================

function [datesdepJD, DeltaVLambert, minr_MC, minr_TC] = ...
   DVLambert(dZcjd, vdep_eme, posCubeSat_eme, vitCubeSat, deltaV)
	//_bs_ dimensions de datesdepJD ? on dirait que c'est une matrice (1xc) (!!!)
	[l,c]=size(vdep_eme);

	// new approach: vdep_eme is a single vector (c=1, but we keep the loop)
	for i=1:c
		[X_eclip, V_eclip, datebis, r_SC, r_TC, r_MC, r_ST, r_SM] = ...
            integrale(dZcjd, position_Z_eme, vdep_eme(:,i));
		datesJD = CL_dat_convert("cjd", "jd", datebis'); 
		datesdepJD(:,i) = datesJD(1,1);
		minr_MC(:,i) = min(r_MC);
		minr_TC(:,i) = min(r_TC);
		DeltaVLambert(:,i) = vdep(:,i) - (vitCubeSat+deltaV);
		DeltaVLambert_norm(:,i) = CL_norm(DeltaVLambert(:,i));
	end
endfunction
//===============================================================================================

function [vdep] = ...
   arrivals_Mars(datecjdTTd, posCubeSat, datecjdTTa)
	//_bs_  To be documented
	// I:	datecjdTTd: date of DeltaV to be applied (decimal date)
	//	posCubeSat: position of Birdy at that time (3x1)
	//      datecjdTTa: array of the arrival dates in decimal days (1xN)
	// O:   vdep: 3xN vectors of the required DeltaV for each arrival date in Ecliptic J2000

    dt = (datecjdTTa - datecjdTTd)*86400; // array of the transit durations in seconds
	[pos_mars_eod, vel_mars_eod] = CL_eph_planet("Mars", datecjdTTa, model="full");
	[pos_mars_eme, vel_mars_eme] = CL_fr_convert("EOD","EME2000", datecjdTTa, pos_mars_eod, vel_mars_eod);
	pos_mars_eclip = Meme2eclip*pos_mars_eme;
	vel_mars_eclip = Meme2eclip*vel_mars_eme;
	[vdep, varr] = CL_man_lambert(posCubeSat, pos_mars_eclip, dt, mu=muSun);
endfunction
//===============================================================================================

//_bs_ (comments pendant debug 8/01/2015)
// EOD2ICRS
// ICRS2BCFSun
// ICRS2BCFMars
// ICRS2ECFTerre
//_bs_

//frame change from EOD to ICRS
function [ricrs,vicrs,jeod2icrs,Meod2icrs]=EOD2ICRS(reod,veod,tcjdtt,ttref)
    [ricrs,vicrs,jeod2icrs]=CL_fr_convert("EOD","ICRS",tcjdtt,reod,veod,tt_tref=ttref);
    Meod2icrs=jeod2icrs(1:3,1:3);
endfunction

//frame change from ICRS to equatorial Sun (BCF Sun)
function [rbcfSun,vbcfSun,jicrs2bcfSun,Micrs2bcfSun]=ICRS2BCFSun(ricrs,vicrs,tcjdtt,ttref)
    [rbcfSun,vbcfSun,jicrs2bcfSun]=CL_fr_bodyConvert("Sun","ICRS","BCF",tcjdtt,ricrs,vicrs,tt_tref=ttref);
    Micrs2bcfSun=jicrs2bcfSun(1:3,1:3);
endfunction

//frame change from ICRS to equatorial Mars (BCF Mars)
function [rbcfMars,vbcfMars,jicrs2bcfMars,Micrs2bcfMars]=ICRS2BCFMars(ricrs,vicrs,posMarsicrs,velMarsicrs,tcjdtt,ttref)
    ricrs_mars=ricrs-posMarsicrs;//position of the cubesat according to Mars ( MC MarsCubesat = SC-SM  SunCubesat-SunMars )
    vicrs_mars=vicrs-velMarsicrs;//velocity of the CubeSat according to Mars 
    [rbcfMars,vbcfMars,jicrs2bcfMars]=CL_fr_bodyConvert("Mars","ICRS","BCF",tcjdtt,ricrs_mars,vicrs_mars,tt_tref=ttref);
    Micrs2bcfMars=jicrs2bcfMars(1:3,1:3);
endfunction

//frame change from ICRS to equatorial Earth (BCF Earth)
function [recfTerre,vecfTerre,jicrs2ecfTerre,Micrs2ecfTerre]=ICRS2ECFTerre(ricrs,vicrs,posTerreicrs,velTerreicrs,tcjdtt,ttref)
    ricrs_Terre=ricrs-posTerreicrs;//position of the cubesat according to the Earth ( EC EarthCubesat = SC-SE  SunCubesat-SunEarth )
    vicrs_Terre=vicrs-velTerreicrs;//velocity of the CubeSat according to the Earth 
   [recfTerre,vecfTerre,jicrs2ecfTerre]=CL_fr_convert("ICRS","ECF",tcjdtt,ricrs_Terre,vicrs_Terre,tt_tref=ttref);
    Micrs2ecfTerre=jicrs2ecfTerre(1:3,1:3);
endfunction
//===============================================================================================

