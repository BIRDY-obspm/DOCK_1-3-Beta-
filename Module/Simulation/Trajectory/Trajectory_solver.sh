#!/bin/bash
# File name: Trajectory_solver.sh
# Final Modified Date: 18/09/2015
# 
# Author: Hao-Chih,Lin (Jim,Lin)
# Email : F44006076@gmail.com  
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
PRODTRAJ=`grep 'PRODTRAJ' $Check_result | awk -F '"' '{printf $2}'`
if [ "$PRODTRAJ" == "True" ]; then
	echo ""
	echo "===Trajectory Solver module===" | tee -a "$Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log"
else
	exit 0
fi

#===Load parameters from Scenario file===
Keep_temp_file=`tac $Scenario_file | grep -m 1 '^ *Keep_temp_file *=' | awk -F '"' '{printf $2}'`
Dyn_traj_config=`tac $Configuration_file | grep -m 1 '^ *Dyn_traj_config *=' | awk -F '"' '{printf $2}'`
Dyn_host_traj_file=`tac $Configuration_file | grep -m 1 '^ *Dyn_host_traj_file *=' | awk -F '"' '{printf $2}'`
#Satellite_name_sce=`tac $Configuration_file | grep -m 1 '^ *Satellite_name *=' | awk -F '"' '{printf $2}'`
#Satellite_start_sce_date=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_start *=' | awk -F '"' '{printf $2}' | awk '{printf $1}'`
#Satellite_start_sce_sec=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_start *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`  
#Satellite_end_sce_date=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_end *=' | awk -F '"' '{printf $2}' | awk '{printf $1}'`
#Satellite_end_sce_sec=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_end *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`

#===Check if the specific directory is existing or not, if not, use the default "Output/Dynamic_quat" folder===		
cd $Configuration_location
Dyn_traj_output_location=`tac $Configuration_file | grep -m 1 '^ *Dyn_traj_output_location *=' | awk -F '"' '{printf $2}'`
if [ ! -d "$Dyn_traj_output_location" ]; then
	Dyn_traj_output_location="$Dock_main_location/Output/Dynamic_traj"
	echo "Use the default output folder which is \"Output/Dynamic_traj/\""
elif [ "$Dyn_traj_output_location" == "." ]; then
	Dyn_traj_output_location=$Configuration_location
else
	# Force the path to be a standard format of absolute path 	
	Dyn_traj_output_location=`cd $Dyn_traj_output_location;pwd`
fi
cd $Dock_main_location
#===Execute the python Trajectory Solver===
if [ $Error_flag == "True" ]; then
	
	cd $Configuration_location
	#---Check the config file---	
	if [ -f "$Dyn_traj_config" ]; then
		if [ "`echo "$Dyn_traj_config" | awk -F / '{print $2}'`" == "" ]; then
			Dyn_traj_config=$Configuration_location/$Dyn_traj_config
		else
			Dyn_traj_config=`cd $(dirname $Dyn_traj_config);pwd`"/"$(basename $Dyn_traj_config)	
		fi
	else
		echo "Config file for trajectory solver not found!!"
		echo "Exit the Trajectory slover"
		exit 0
	fi

	#---Check the host trajectory file---	
	if [ -f "$Dyn_host_traj_file" ]; then
		if [ "`echo "$Dyn_host_traj_file" | awk -F / '{print $2}'`" == "" ]; then
			Dyn_host_traj_file=$Configuration_location/$Dyn_host_traj_file
		else
			Dyn_host_traj_file=`cd $(dirname $Dyn_host_traj_file);pwd`"/"$(basename $Dyn_host_traj_file)	
		fi
	else
		echo "Host trajectory file for trajectory solver not found!!"
		echo "Exit the Trajectory slover"
		exit 0
	fi

	cd $Dock_main_location	
	#---Grep the output file name from config file---
	output_trajectory_file=`tac $Dyn_traj_config | grep -m 1 '^ *output_trajectory_file *=' | awk -F '"' '{printf $2}'`
	output_ephemeris_file=`tac $Dyn_traj_config | grep -m 1 '^ *output_ephemeris_file *=' | awk -F '"' '{printf $2}'`	
	
	#---Copy the host trajectory file from "Input/Dyn_traj" (or specified folder) folder to "Tralectory_solver" folder---
	cp -f $Dyn_traj_config $Dock_main_location/Module/Simulation/Trajectory/TrajectorySolver/config.py	

	#---Copy the config.py file from "Input/Dyn_traj" (or specified folder) folder to "Tralectory_solver" folder---
	cp -f $Dyn_host_traj_file $Dock_main_location/Module/Simulation/Trajectory/TrajectorySolver/host-trajectories/`basename $Dyn_host_traj_file`

	#---Change current direction to "Tralectory_solver" folder---
	cd $Dock_main_location/Module/Simulation/Trajectory/TrajectorySolver/
	Current_location=`pwd`	
	
	#---Execute the python version of trajectory solver---
	echo "Executing the trajectory solver..."	
	python main.py >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log
	echo "Success !!"
	
	#---Copy the result to specified folder---
	cp -f $Current_location/output-trajectories/$output_trajectory_file $Dyn_traj_output_location/Traj-$Date.traj
	cp -f $Current_location/output-trajectories/$output_ephemeris_file $Dyn_traj_output_location/Ephemeris-$Date.traj

	echo "New trajectory file has been created."
	echo "File name: Traj-$Date.traj"

	if [ $Keep_temp_file == "False" ]; then
		rm -f $Current_location/config.py
		rm -f $Current_location/host-trajectories/`basename $Dyn_host_traj_file`
		rm -f $Current_location/output-trajectories/$output_trajectory_file
		rm -f $Current_location/output-trajectories/$output_ephemeris_file
	fi

	#---Put the Dynamic_traj file name into "Check_result.tmp"
	{ echo "New_traj = \"$Dyn_traj_output_location/Traj-$Date.traj\"" ; } >> $Dock_main_location/Module/Tmp/Check_result.tmp
fi
