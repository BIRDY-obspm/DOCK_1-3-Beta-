#!/bin/bash
# File name: Easy_traj_gen.sh
# Final Modified Date: 25/09/2015 (for v1.5 Beta)
# 
# Author: Hao-Chih,Lin (Jim,Lin)
# Email : F44006076@gmail.com  
#
#===================================================
#=======================Program=====================
#===================================================

#===Load infromation from "Check_result.tmp" file===
Check_result=Module/Tmp/Check_result.tmp
Exit_flag=`tac $Check_result | grep -m 1 '^ *Exit *=' | awk -F '"' '{printf $2}'`
if [ "$Exit_flag" == "True" ]; then
	exit 0
fi

Date=`tac $Check_result | grep -m 1 '^ *Date *=' | awk -F '"' '{printf $2}'`
Scenario_file=`tac $Check_result | grep -m 1 '^ *Scenario_name *=' | awk -F '"' '{printf $2}'`
Scenario_location=`tac $Check_result | grep -m 1 '^ *Scenario_location *=' | awk -F '"' '{printf $2}'`
Configuration_file=`tac $Check_result | grep -m 1 '^ *Configuration_name *=' | awk -F '"' '{printf $2}'`
Configuration_location=`tac $Check_result | grep -m 1 '^ *Configuration_location *=' | awk -F '"' '{printf $2}'`
Error_flag=`tac $Check_result | grep -m 1 '^ *Error_flag *=' | awk -F '"' '{printf $2}'`
Dock_main_location=`pwd`

#===Check the need of this module===
EASYTRAJ=`grep 'EASYTRAJ' $Check_result | awk -F '"' '{printf $2}'`
if [ "$EASYTRAJ" == "True" ]; then
	echo ""
	echo "===Easy trajectory module===" | tee -a "$Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log"
else
	exit
fi

#===Load parameters from Scenario file===
Keep_temp_file=`tac $Scenario_file | grep -m 1 '^ *Keep_temp_file *=' | awk -F '"' '{printf $2}'`
Satellite_Sat_name=`tac $Configuration_file | grep -m 1 '^ *Satellite_name *=' | awk -F '"' '{printf $2}'`
Satellite_Body_name=`tac $Configuration_file | grep -m 1 '^ *Satellite_parentpath *=' | awk -F '"' '{printf $2}' | awk -F / '{print $2}'`
Satellite_start_sce_date=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_start *=' | awk -F '"' '{printf $2}' | awk '{printf $1}'`
Satellite_start_sce_sec=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_start *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`  
Satellite_end_sce_date=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_end *=' | awk -F '"' '{printf $2}' | awk '{printf $1}'`
Satellite_end_sce_sec=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_end *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`
Simulation_step_size=`tac $Scenario_file | grep -m 1 '^ *Simulation_step_size *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`

Easy_traj_start_date=`tac $Scenario_file | grep -m 1 '^ *Easy_traj_start *=' | awk -F '"' '{printf $2}' | awk '{printf $1}'`
Easy_traj_start_sec=`tac $Scenario_file | grep -m 1 '^ *Easy_traj_start *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`
Easy_traj_end_date=`tac $Scenario_file | grep -m 1 '^ *Easy_traj_end *=' | awk -F '"' '{printf $2}' | awk '{printf $1}'`
Easy_traj_end_sec=`tac $Scenario_file | grep -m 1 '^ *Easy_traj_end *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`
Easy_traj_step=`tac $Scenario_file | grep -m 1 '^ *Easy_traj_step *=' | awk -F '"' '{printf $2}'`
Easy_traj_type=`tac $Scenario_file | grep -m 1 '^ *Easy_traj_type *=' | awk -F '"' '{printf $2}'`

Easy_traj_sma=`tac $Scenario_file | grep -m 1 '^ *Easy_traj_sma *=' | awk -F '"' '{printf $2}'`
Easy_traj_ecc=`tac $Scenario_file | grep -m 1 '^ *Easy_traj_ecc *=' | awk -F '"' '{printf $2}'`
Easy_traj_inc=`tac $Scenario_file | grep -m 1 '^ *Easy_traj_inc *=' | awk -F '"' '{printf $2}'`
Easy_traj_pom=`tac $Scenario_file | grep -m 1 '^ *Easy_traj_pom *=' | awk -F '"' '{printf $2}'`
Easy_traj_gom=`tac $Scenario_file | grep -m 1 '^ *Easy_traj_gom *=' | awk -F '"' '{printf $2}'`
Easy_traj_anm=`tac $Scenario_file | grep -m 1 '^ *Easy_traj_anm *=' | awk -F '"' '{printf $2}'`
#===Check if the specific directory is existing or not, if not, use the default "Output/Easy_traj" folder===		
cd $Configuration_location
Easy_traj_output_location=`tac $Configuration_file | grep -m 1 '^ *Easy_traj_output_location *=' | awk -F '"' '{printf $2}'`
if [ ! -d "$Easy_traj_output_location" ]; then
	Easy_traj_output_location="$Dock_main_location/Output/Easy_traj"
	echo "Use the default output folder which is \"Output/Easy_traj/\""
elif [ "$Easy_traj_output_location" == "." ]; then
	Easy_traj_output_location=$Configuration_location
else
	# Force the path to be a standard format of absolute path 	
	Easy_traj_output_location=`cd $Easy_traj_output_location;pwd`
fi
cd $Dock_main_location

#===Check if the definition of parameters is correct or not===
Error_count=0
#---Start date---
if [ "$Easy_traj_start_date" == "" ]; then
	start_date=$Satellite_start_sce_date
else
	start_date=$Easy_traj_start_date
fi
if echo $start_date | egrep -q '^[0-9]+$' ; then
	echo "Start date is: $start_date (MJD)"
else
	echo "Definition of 'Start date' is wrong!!\033[0m"
	(( Error_count += 1 ))
fi
#---Start sec---
if [ "$Easy_traj_start_sec" == "" ]; then
	start_sec=$Satellite_start_sce_sec
else
	start_sec=$Easy_traj_start_sec
fi
if echo $start_sec | egrep -q '^[0-9.]+$' ; then
	echo "Start sec is: $start_sec "
else
	echo "Definition of 'Start sec' is wrong!!"
	(( Error_count += 1 ))
fi
#---End date---
if [ "$Easy_traj_end_date" == "" ]; then
	end_date=$Satellite_end_sce_date
else
	end_date=$Easy_traj_end_date
fi
if echo $end_date | egrep -q '^[0-9]+$' ; then
	echo "End date is: $end_date (MJD)"
else
	echo "Definition of 'End date' is wrong!!"
	(( Error_count += 1 ))
fi
#---End sec---
if [ "$Easy_traj_end_sec" == "" ]; then
	end_sec=$Satellite_end_sce_sec
else
	end_sec=$Easy_traj_end_sec
fi
if echo $end_sec | egrep -q '^[0-9.]+$' ; then
	echo "End sec is: $end_sec "
else
	echo "Definition of 'End sec' is wrong!!"
	(( Error_count += 1 ))
fi
#---Step size---
if [ "$Easy_traj_step" == "" ]; then
	step_size=$Simulation_step_size
else
	step_size=$Easy_traj_step
fi
if echo $step_size | egrep -q '^[0-9.]+$' ; then
	echo "Step size is: $step_size (sec)"
else
	echo "Definition of 'Step size' is wrong!!"
	(( Error_count += 1 ))
fi
#---Result---
if [ ! "$Error_count" == 0 ]; then
	echo "There is(are) $Error_count error(s)!!"
	echo "Exit the Easy-trajectory module"
	exit 0
fi

#---Check the Sat name---
if [ "$Satellite_Sat_name" = "" ]; then
	Satellite_Sat_name="Undefined"
fi
if [ "$Satellite_Body_name" = "" ]; then
	Satellite_Body_name="Undefined"
fi

#---Send a title into Log file---
{ echo "===Easy Trajectory===" ; } >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log

#===Creating new Scilab file in order to run dynamic model in Xcos environment===
cd Module/Easy-trajectory/
Current_location=`pwd`	
echo ""
echo "Creating new Scilab .sce file for easy trajectory......"

cat > $Current_location/Easytraj-tmp-$Date.sce <<EOF
clear
clc
cd $Current_location
// Mean orbital elements, frame = ECI(EME2000)
sma = $Easy_traj_sma * 1000; // semi major axis (unit m)
ecc = $Easy_traj_ecc; // eccentricity 
inc = $Easy_traj_inc * %pi/180; // inclination
pom = $Easy_traj_pom * %pi/180; // Argument of perigee
gom = $Easy_traj_gom * %pi/180; // RAAN (Longitude of the ascending node)
anm = $Easy_traj_anm * %pi/180; // Mean anomaly

// Orbit type: Keplerian or Circular
type_oe = "$Easy_traj_type";

// Simulation time
start_time = [$start_date $start_sec]; // MJD [date sec]
end_time = [$end_date $end_sec];
step_size = $step_size; // Unit: sec

// CIC output setting
Sat_name = '$Satellite_Sat_name';
Body_name = '$Satellite_Body_name';
File_path = '$Easy_traj_output_location/Easy-traj-$Date.txt';

// Call the EasyTraj2CIC function
exec('EasyTraj_gen.sci');

EasyTraj_gen(sma, ecc, inc, pom, gom, anm, type_oe, start_time, end_time, step_size, Sat_name, Body_name, File_path);

exit();
EOF

echo "New .sce file has been created."
echo "File name: Easytraj-tmp-$Date.sce"
echo "" 		
echo "Executing the Scilab......"

#---Execute Scilab---
scilab-adv-cli  -f Easytraj-tmp-$Date.sce -nb >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log

if [ $Keep_temp_file == "False" ]; then
	rm -f Easytraj-tmp-$Date.sce
fi

echo "New Easy traj CIC file was created."
echo "File name is: Easy-traj-$Date.txt"

#---Put the Easy-quaternion file name into "Check_result.tmp"
{ echo "New_traj = \"$Easy_traj_output_location/Easy-traj-$Date.txt\" by \"EASYTRAJ\"" ; } >> $Dock_main_location/Module/Tmp/Check_result.tmp

