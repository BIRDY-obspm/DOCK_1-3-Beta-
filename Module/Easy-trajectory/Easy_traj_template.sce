clear
clc

// Mean orbital elements, frame = ECI(EME2000)
sma = 6800.e3; // semi major axis (unit m)
ecc = 1.e-3;   // eccentricity 
inc = 45 * %pi/180; // inclination
pom = %pi/2; // Argument of perigee
gom = 5.5289325; // RAAN (Longitude of the ascending node)
anm = 0; // Mean anomaly

// Orbit type: Keplerian or Circular
type_oe = "Circular";

// Simulation time
start_time = [51480 0.0]; // MJD [date sec]
end_time = [51509 10];
step_size = 100; // Unit: sec

// CIC output setting
Sat_name = 'Birdy';
Body_name = 'EARTH';
File_path = '/home/birdy/Software/Backup/Easy_Traj/test01.txt';

// Call the EasyTraj2CIC function
exec('EasyTraj_gen.sci');

EasyTraj_gen(sma, ecc, inc, pom, gom, anm, type_oe, start_time, end_time, step_size, Sat_name, Body_name, File_path);

exit();
