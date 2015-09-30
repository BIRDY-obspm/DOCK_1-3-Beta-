#!/bin/bash
# File name: Trajectory_solver.sh
# Final Modified Date: 11/08/2015
# 
# Author: Hao-Chih,Lin (Jim,Lin)
# Email : F44006076@gmail.com  
#===================================================
#=======================Program=====================
#===================================================

#===Load infromation from "Check_result.tmp" file===
Check_result=Module/Tmp/Check_result.tmp
Date=`grep 'Date' $Check_result | cut -d '"' -f 2`
Scenario_file=`grep 'Scenario_name' $Check_result | cut -d '"' -f 2`
Configuration_file=`grep 'Configuration_name' $Check_result | cut -d '"' -f 2`
Error_flag=`grep 'Error_flag' $Check_result | cut -d '"' -f 2`
New_quat=`grep 'New_quat' $Check_result | cut -d '"' -f 2`
New_trajectory=`grep 'New_trajectory' $Check_result | cut -d '"' -f 2`
Parent_location=`pwd`

if [ $Error_flag == "True" ] && [ "$New_trajectory" = "" ]; then
	cd Module/Simulation/Trajectory/

	#---Execute the Trajectory Solver---
	nohup nice -n 15 ./BIRDY_TS_batch &

	echo "Success !!"
fi
