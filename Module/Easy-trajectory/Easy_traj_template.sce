// File name: Easy_traj_template.sce
// Final Modified Date: 23/10/2015 
// Author: Hao-Chih,Lin (Jim,Lin)
// Email : F44006076@gmail.com
//
// ==============================================================
// ===========================LICENSE============================
// ==============================================================
// This file is part of DOCKS.
//
// DOCKS is free software: you can redistribute it and/or modify
// it under the terms of the  GNU LESSER GENERAL PUBLIC LICENSE 
// as published by the Free Software Foundation, either version 
// 3 of the License, or any later version.
//
// DOCKS is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU LESSER GENERAL PUBLIC LICENSE for more details.
//
// You should have received a copy of the 
// GNU LESSER GENERAL PUBLIC LICENSE along with DOCKS.
// If not, see <http://www.gnu.org/licenses/lgpl.txt>.


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
