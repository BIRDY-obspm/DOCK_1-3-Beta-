#!/bin/bash
# File name: Extract_Celestia.sh
# Final Modified Date: 23/10/2015
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
Dock_main_location=`pwd`

#===Check the need of this module===
EXTRCEL=`grep 'EXTRCEL' $Check_result | awk -F '"' '{printf $2}'`
if [ "$EXTRCEL" == "True" ]; then
	echo ""
	echo "===Extract Celestia module===" | tee -a "$Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log"
else
	exit
fi

#===Check if new VTS project file is existing or not, and make sure that the VTS software has been executed===02092015
#New_VTS_file=`tac $Check_result | grep -m 1 '^ *New_VTS_file *=' | awk -F '"' '{printf $2}'`
#EXEVTS=`grep 'EXEVTS' $Check_result | awk -F '"' '{printf $2}'`
#if [ "$New_VTS_file" == "" ] || [ ! "$EXEVTS" == "True" ]; then
#	echo -e "\e[91mEither new VTS file not found or VTS software hasn't been executed\e[0m"
#	echo -e "\e[91mExit the Extract Celestia module\e[0m"
#	exit 0
#fi

#===Check the location of VTS software===
cd $Configuration_location
VTS_software_location=`tac $Configuration_file | grep -m 1 '^ *VTS_software_location *=' | awk -F '"' '{printf $2}'`
if [ ! -d "$VTS_software_location" ]; then
	echo "VTS software folder not found!!"
	echo "Exit the Extract Celestia module"
	exit 0
else
	VTS_software_location=`cd $VTS_software_location;pwd`
fi
cd $Dock_main_location

#===Check the output location of Celestia Add-on===
cd $Configuration_location
Celestia_output_location=`tac $Configuration_file | grep -m 1 '^ *Celestia_output_location *=' | awk -F '"' '{printf $2}'`
if [ ! -d "$Celestia_output_location" ]; then
	Celestia_output_location="$Dock_main_location/Output/Celestia_Addon"
	echo "Use the default output folder which is \"Output/Celestia_Addon/\""
elif [ "$Celestia_output_location" == "." ]; then
	Celestia_output_location=$Configuration_location
else
	# Force the path to be a standard format of absolute path 	
	Celestia_output_location=`cd $Celestia_output_location;pwd`
fi
cd $Dock_main_location

#===Check the Celestia folder which locates in VTS software===
if [ ! -d "$VTS_software_location/Apps/Celestia/bin" ]; then
	echo "Celestia/bin folder not found!!"
	echo "Exit the Extract Celestia module"
	exit 0
else
	Celestia_location=`cd $VTS_software_location/Apps/Celestia/bin;pwd`
fi

#===Find how many "Celestia" Apps were defined in VTS project file===02092015
#Celestia_num=`grep '<AppState Id' $New_VTS_file | wc -l`
#for check_num in $(seq 1 $Celestia_num)
#do
#	Id_num[(($check_num - 1))]=`grep '<AppState Id' $New_VTS_file | head -n $check_num | tail -n 1 | awk -F '"' '{printf $2}'`
#done

#===Search and copy the Celestia add-on folder created by VTS software===02092015
#for ((check_num=0; check_num<${#Id_num[@]}; check_num++))
#do
#	if [ -d "$Celestia_location/extras_${Id_num[$check_num]}" ]; then
#		cp -a "$Celestia_location/extras_${Id_num[$check_num]}" $Celestia_output_location
#		echo "Copy the \"extras_${Id_num[$check_num]}\" folder to $Celestia_output_location"
#	else
#		echo -e "\e[91mCan not find \"extras_${Id_num[$check_num]}\" folder\e[0m"
#	fi
#done

#===Search and copy the Celestia add-on folder created by VTS software===02092015
cd $Celestia_location
extras_num=`find -type d -name 'extras_*' | wc -l`

if [ "$extras_num" == "0" ]; then
	echo "There is not any Celestia Add-on in App folder" 
else
	for ((check_num=1; check_num<=$extras_num; check_num++))
	do
		Addon_folder=`basename $(find -type d -name 'extras_*' | head -n $check_num | tail -n 1)`		
		cp -a $Celestia_location/$Addon_folder $Celestia_output_location
		echo "Found \"$Addon_folder\" Add-on folder"
	done
	echo "Copy all Add-on folders to following location:"
	echo "$Celestia_output_location"
fi
cd $Dock_main_location
#===Send a title into Log file===
{
	echo "===Extract_Celestia==="
} >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log
