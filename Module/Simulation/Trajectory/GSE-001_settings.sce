//=========================================================
// GSE-001_settings.sce, v1.3 (BIRDY_TS: Trajectory solver)
//=========================================================
// date : 03-Feb-2015
// Ref: GSE-001
// CL=1
// version 1.3
// by Boris SEGRET from v1.2
//  + Audrey PORQUET prior to v1.2 (former name "conf_file.sce")
//
// Also includes the call to sub-routines:
//	(call to GSE-001_inputs.sce)
//	(call to GSE-001_functions.sce)


exec('GSE-001_inputs.sce');
CL_init; //(CelestLab) creates variables containing physical quantities and constants commonly used.
exec('GSE-001_functions.sce');

//_bs_ PAREMETRES DE REGLAGES ==>>
//	ICI sont parametrees des valeurs du pgm principal qui etaient ecrites en dur
//	Elles seront à initialiser plus intelligemment lors d'une future version
bs_size = 30000000; // (en intro pgm principal) extension de la taille de la memoire (requis par mauvaise programmation)
stacksize(bs_size);
//_bs_ stacksize('max');
bs_units = 1000.; // conversion traject. Hote en km et km/s vers S.I.pour CelestLab en m et m/s
bs_blackdot = 780; // index du point "black" sur graphiques
bs_espacesArr = 10; // espace en j. entre 2 dates d'arrivées (fonction arrivals_Mars)
bs_nbDatesDep = 1; // nb de dates avant et après sortie de SOI Terre pour calculer le DeltaV requis
bs_espacesDep = 25; // espace en nb.de lignes d'inputs entre les dates de sortie de SOI
//_bs_ PAREMETRES DE REGLAGES <<==

PbLambertAccuracy = 2; // Lambert Pb accuracy compared to Numerical integration, in days
bs_nominalArr = 227; // duree nominale de cruise (en j., fonction arrivals_Mars)
bs_nbDatesArr = 50; // choix d'un nb de dates possibles d'arrivees dans le pb de Lambert (fonction arrivals_Mars)
d2v = 1/20.; // Delta-V accuracy (in m/s) of the Electric Propulsion, i.e. about 1H prop.

deltaV=[0;0;0]; //_bs_ to be specified in intensity and to align with the ejection vector

//_bs_ these parameters should be integrated in the corresponding Solar Bodies models
muSun = CL_dataGet("body.Sun.mu"); //Gravitational constant of the Sun m^3 s^-2
eqRadSun = CL_dataGet("body.Sun.eqRad"); //Equatorial Radius of the Sun in meter
J2Sun=2e-7; //The J2 of the Sun

muMars = CL_dataGet("body.Mars.mu");//Gravitational constant of Mars m^3 s^-2
eqRadMars = CL_dataGet("body.Mars.eqRad"); //Equatorial Radius of the Mars in meter
J2Mars= 1.96045e-3;

muEarth = CL_dataGet("body.Earth.mu");//Gravitational constant of the Earth m^3 s^-2
eqRadEarth = CL_dataGet("body.Earth.eqRad"); //Equatorial Radius of the Earth in meter

epsilon=23+(26/60)+(21.4096/3600); //obliquity of the ecliptic
c=cosd(epsilon); //cosine epsilon
s=sind(epsilon); //sinus epsilon
//_bs_

Meme2eclip=[1,0,0;0,c,s;0,-s,c]; //matrix which transforms the J2000 equatorial coordinates to J2000 eclitic coordinates

// END OF SETTINGS

