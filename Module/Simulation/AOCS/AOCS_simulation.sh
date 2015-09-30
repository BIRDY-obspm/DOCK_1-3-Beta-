#!/bin/bash
# File name: AOCS_simulation.sh
# Version of DOCK: 1.3
# Final Modified Date: 25/08/2015
# 
# Author: Hao-Chih,Lin (Jim,Lin)
# Email : F44006076@gmail.com  
#===================================================
#=======================Program=====================
#===================================================

#===Load infromation from "Check_result.tmp" file===
Check_result=Module/Tmp/Check_result.tmp
Date=`tac $Check_result | grep -m 1 '^ *Date *=' | awk -F '"' '{printf $2}'`
Scenario_file=`tac $Check_result | grep -m 1 '^ *Scenario_name *=' | awk -F '"' '{printf $2}'`
Configuration_file=`tac $Check_result | grep -m 1 '^ *Configuration_name *=' | awk -F '"' '{printf $2}'`
Error_flag=`tac $Check_result | grep -m 1 '^ *Error_flag *=' | awk -F '"' '{printf $2}'`
New_quat=`tac $Check_result | grep -m 1 '^ *New_quat *=' | awk -F '"' '{printf $2}'`
New_trajectory=`tac $Check_result | grep -m 1 '^ *New_trajectory *=' | awk -F '"' '{printf $2}'`
Dock_main_location=`pwd`

#===Check the need of this module===
PRODQUAT=`grep 'PRODQUAT' $Check_result | awk -F '"' '{printf $2}'`
if [ "$PRODQUAT" == "True" ]; then
	echo  -e "\033[33m===Dynamic model for quaternion module===\033[0m" | tee -a "$Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log"
else
	exit
fi

#===Load parameters from Scenario file===
Keep_temp_file=`tac $Scenario_file | grep -m 1 '^ *Keep_temp_file *=' | awk -F '"' '{printf $2}'`
Satellite_name_sce=`tac $Configuration_file | grep -m 1 '^ *Satellite_name *=' | awk -F '"' '{printf $2}'`
Satellite_start_sce_date=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_start *=' | awk -F '"' '{printf $2}' | awk '{printf $1}'`
Satellite_start_sce_sec=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_start *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`  
Satellite_end_sce_date=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_end *=' | awk -F '"' '{printf $2}' | awk '{printf $1}'`
Satellite_end_sce_sec=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_end *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`

#===Check if the specific directory is existing or not, if not, use the default "Output/Dynamic_quat" folder===		
Dyn_quat_output_location=`tac $Configuration_file | grep -m 1 '^ *Dyn_quat_output_location *=' | awk -F '"' '{printf $2}'`
if [ ! -d "$Dyn_quat_output_location" ]; then
	Dyn_quat_output_location="$Dock_main_location/Output/Dynamic_quat"
	echo "Use the default output folder which is \"Output/Dynamic_quat/\""
else
	#---remove the "/" at the end of path---	
	if [ "${Dyn_quat_output_location: -1}" == "/" ]; then
		Dyn_quat_output_location=`echo ${Dyn_quat_output_location: 0:-1}`
	fi
fi

#===Creating new Scilab file in order to run dynamic model in Xcos environment===
if [ $Error_flag == "True" ]; then
	cd Module/Simulation/AOCS/
	Current_location=`pwd`	
	echo "Creating new Scilab .sce file......"
	{
		echo "//===== Load functions for Xcos ====="
		echo "exec('$Current_location/LeastNormTorque.sci')"
		echo "" 
		echo "exec('$Current_location/NDI_rateControl.sci')"
		echo "" 
		echo "exec('$Current_location/OmegaPrime.sci')"
		echo "" 
		echo "exec('$Current_location/QuaternionPD.sci')"
		echo "" 
		echo "//===== Load parameters for Xcos ====="
		echo "exec('$Current_location/load_para.sce') "
		echo ""
		echo "//===== Execute the Xcos ====="
		echo "importXcosDiagram('$Current_location/BIRDY_Dynamic_Attitude_Model.zcos')"
		echo ""
		echo "typeof(scs_m) //The diagram data structure"
		echo ""
		echo "scs_m.props.context;"
		echo "xcos_simulate(scs_m, 4);"
		echo ""
		echo "//===== Load the result of Xcos into Scilab workspace ====="
		echo "BIRDY_ATT;"
		echo ""
		echo "//===== Creating CIC file for VTS ====="
		echo "exec('$Current_location/XcosToVTSQuat.sci')"
		echo "XcosToVTSQuat(BIRDY_ATT.values,$Satellite_start_sce_date,'QUATERNION','$Satellite_name_sce','$Dyn_quat_output_location/','$Satellite_name_sce-quaternion-$Date.txt')"
		echo ""
		echo "//===== Exit for Scilab ====="
		echo "exit;" 
	} > $Satellite_name_sce-AOCS-$Date.sce
	echo -e "\e[92mNew .sce file has been created. \e[0m"
	echo -e "\e[92mFile name: $Satellite_name_sce-AOCS-$Date.sce\e[0m"
	echo "" 		
	echo -e "Executing the Scilab/Xcos......"
	#---Send a title into Log file---
	{ echo "===AOCS Scilab===" ; } >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log
	#---Execute Scilab---
	scilab-adv-cli  -f $Satellite_name_sce-AOCS-$Date.sce -nb >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log

	if [ $Keep_temp_file == "False" ]; then
		rm -f $Satellite_name_sce-AOCS-$Date.sce
	fi

	echo -e "\e[92mNew Quarernion CIC file was created.\e[0m"
	echo -e "\e[92mFile name is: $Satellite_name_sce-quaternion-$Date.txt\e[0m"
	
	#---Put the Easy-quaternion file name into "Check_result.tmp"
	{ echo "New_quat = \"$Dyn_quat_output_location/$Satellite_name_sce-quaternion-$Date.txt\"" ; } >> $Dock_main_location/Module/Tmp/Check_result.tmp
fi
