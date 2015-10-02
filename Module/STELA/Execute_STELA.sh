#!/bin/bash
# File name: Execute_STELA.sh
# Final Modified Date: 23/09/2015
# 
# Abstract:
# This program will only launch GUI version of STELA
#
# Author: Hao-Chih,Lin (Jim,Lin)
# Email : F44006076@gmail.com  
#===================================================
#=======================Program=====================
#===================================================

#===Load necessary infromation from "Check_result" file===
#---Check if "Exit_flag" is set or not---
Check_result=Module/Tmp/Check_result.tmp
Exit_flag=`tac $Check_result | grep -m 1 '^ *Exit *=' | awk -F '"' '{printf $2}'`
if [ "$Exit_flag" == "True" ]; then
	exit 0
fi

#---Load definition of basic parameters---  
Date=`tac $Check_result | grep -m 1 '^ *Date *=' | awk -F '"' '{printf $2}'`
Scenario_file=`tac $Check_result | grep -m 1 '^ *Scenario_name *=' | awk -F '"' '{printf $2}'`
Configuration_file=`tac $Check_result | grep -m 1 '^ *Configuration_name *=' | awk -F '"' '{printf $2}'`
Error_flag=`tac $Check_result | grep -m 1 '^ *Error_flag *=' | awk -F '"' '{printf $2}'`
New_VTS_file=`tac $Check_result | grep -m 1 '^ *New_VTS_file *=' | awk -F '"' '{printf $2}'`
Dock_main_location=`pwd`

#===Check the need of this module===
EXESTELA=`grep 'EXESTELA' $Check_result | awk -F '"' '{printf $2}'`
if [ "$EXESTELA" == "True" ]; then
	echo  -e "\033[33m===STELA execution module===\033[0m" | tee -a "$Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log"
else
	exit
fi

#===Load parameters from specific configuration file===
cd $Configuration_location
STELA_software_location=`tac $Configuration_file | grep -m 1 '^ *STELA_software_location *=' | awk -F '"' '{printf $2}'`
if [ ! -d "$STELA_software_location" ]; then
	echo -e "\e[91mSTELA software folder not found!!\e[0m"
	echo -e "\e[91mExit the EXESTELA module\e[0m"
	exit 0
else
	STELA_software_location=`cd $STELA_software_location;pwd`
fi

STELA_exe_path=$STELA_software_location"/bin/stela.sh"
if [ ! -f "$STELA_exe_path" ]; then
	echo -e "\e[91mSTELA execution file not found!!\e[0m"
	echo -e "\e[91mExit the EXESTELA module\e[0m"
	exit 0
fi
cd $Dock_main_location
#===Send a title into Log file===
{
	echo "===STELA Execute==="
} >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log

#===Execute the STELA===
echo "Executing the STELA GUI......"
cd $STELA_software_location
./bin/stela.sh # >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log
