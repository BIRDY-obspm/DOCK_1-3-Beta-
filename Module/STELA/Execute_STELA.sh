#!/bin/bash
# File name: Execute_STELA.sh
# Final Modified Date: 23/10/2015
# 
# Abstract:
# This program will only launch GUI version of STELA
#
# Author: Hao-Chih,Lin (Jim,Lin)
# Email : F44006076@gmail.com  
#
# ==============================================================
# ===========================LICENSE============================
# ==============================================================
# This file is part of DOCKS.
#
# DOCKS is free software: you can redistribute it and/or modify
# it under the terms of the  GNU LESSER GENERAL PUBLIC LICENSE 
# as published by the Free Software Foundation, either version 
# 3 of the License, or any later version.
#
# DOCKS is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU LESSER GENERAL PUBLIC LICENSE for more details.
#
# You should have received a copy of the 
# GNU LESSER GENERAL PUBLIC LICENSE along with DOCKS.
# If not, see <http://www.gnu.org/licenses/lgpl.txt>.
#
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
	echo ""
	echo "===STELA execution module===" | tee -a "$Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log"
else
	exit
fi

#===Load parameters from specific configuration file===
cd $Configuration_location
STELA_software_location=`tac $Configuration_file | grep -m 1 '^ *STELA_software_location *=' | awk -F '"' '{printf $2}'`
if [ ! -d "$STELA_software_location" ]; then
	echo "STELA software folder not found!!"
	echo "Exit the EXESTELA module"
	exit 0
else
	STELA_software_location=`cd $STELA_software_location;pwd`
fi

STELA_exe_path=$STELA_software_location"/bin/stela.sh"
if [ ! -f "$STELA_exe_path" ]; then
	echo "STELA execution file not found!!"
	echo "Exit the EXESTELA module"
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
