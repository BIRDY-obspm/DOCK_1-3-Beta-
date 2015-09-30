#!/bin/bash
# File name: Execute_VTS.sh
# Version of DOCK: 1.3
# Final Modified Date: 25/08/2015
# 
# Abstract:
# This program will automatically check if there is a new VTS project created by other module or not.
# If yes, the new VTS project will be executed.
# If no, the original VTS project defined in "Scenario" file will be executed.  
#
# Author: Hao-Chih,Lin (Jim,Lin)
# Email : F44006076@gmail.com  
#===================================================
#=======================Program=====================
#===================================================

#===Load "Date" infromation from "Check_result" file===
Check_result=Module/Tmp/Check_result.tmp
Date=`tac $Check_result | grep -m 1 '^ *Date *=' | awk -F '"' '{printf $2}'`
Scenario_file=`tac $Check_result | grep -m 1 '^ *Scenario_name *=' | awk -F '"' '{printf $2}'`
Configuration_file=`tac $Check_result | grep -m 1 '^ *Configuration_name *=' | awk -F '"' '{printf $2}'`
Error_flag=`tac $Check_result | grep -m 1 '^ *Error_flag *=' | awk -F '"' '{printf $2}'`
New_VTS_file=`tac $Check_result | grep -m 1 '^ *New_VTS_file *=' | awk -F '"' '{printf $2}'`
Dock_main_location=`pwd`

#===Check the need of this module===
EXEVTS=`grep 'EXEVTS' $Check_result | awk -F '"' '{printf $2}'`
if [ "$EXEVTS" == "True" ]; then
	echo  -e "\033[33m===VTS execution module===\033[0m" | tee -a "$Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log"
else
	exit
fi

#===Load parameters from specific configuration file===
VTS_project=`tac $Configuration_file | grep -m 1 '^ *VTS_project_file *=' | awk -F '"' '{printf $2}'`
VTS_software_location=`tac $Configuration_file | grep -m 1 '^ *VTS_software_location *=' | awk -F '"' '{printf $2}'`

#===Send a title into Log file===
{
	echo "===VTS Execute==="
} >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log

#===Check the "Error-flag"===
if [ $Error_flag == "False" ]; then
	echo "Executing the VTS......"
	cd $VTS_software_location
	./startVTS --project $VTS_project >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log
else
	if [ "$New_VTS_file" == "" ]; then
		echo -e "\e[96m[Warning] There is not a new created VTS project.\e[0m"
		echo -e "\e[96m[Warning] Launch the default VTS project defined in Scenario file.\e[0m"
		echo "Executing the VTS......"		
		cd $VTS_software_location 
		./startVTS --project $VTS_project >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log
	else
		echo "Executing the VTS......"
		cd $VTS_software_location 
		./startVTS --project $New_VTS_file >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log
	fi
fi
