#!/bin/bash
# File name: AOCS_simulation.sh
# Final Modified Date: 29/09/2015
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
PRODQUAT=`grep 'PRODQUAT' $Check_result | awk -F '"' '{printf $2}'`
if [ "$PRODQUAT" == "True" ]; then
	echo ""
	echo "===Dynamic model for quaternion module===" | tee -a "$Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log"
else
	exit
fi

#===Load parameters from Scenario file===
Keep_temp_file=`tac $Scenario_file | grep -m 1 '^ *Keep_temp_file *=' | awk -F '"' '{printf $2}'`
Dyn_quat_para_setting=`tac $Configuration_file | grep -m 1 '^ *Dyn_quat_para_setting *=' | awk -F '"' '{printf $2}'`
Dyn_quat_seq_inputs_file=`tac $Configuration_file | grep -m 1 '^ *Dyn_quat_seq_inputs_file *=' | awk -F '"' '{printf $2}'`
Satellite_name_sce=`tac $Configuration_file | grep -m 1 '^ *Satellite_name *=' | awk -F '"' '{printf $2}'`
Satellite_REF_FRAME_A=`tac $Configuration_file | grep -m 1 '^ *Satellite_ref_frame_A *=' | awk -F '"' '{printf $2}'`
Satellite_REF_FRAME_B=`tac $Configuration_file | grep -m 1 '^ *Satellite_ref_frame_B *=' | awk -F '"' '{printf $2}'`
Satellite_ATTITUDE_DIR=`tac $Configuration_file | grep -m 1 '^ *Satellite_attitude_dir *=' | awk -F '"' '{printf $2}'`
Satellite_TIME_SYSTEM=`tac $Configuration_file | grep -m 1 '^ *Satellite_time_system *=' | awk -F '"' '{printf $2}'`

#===Check if the specific directory is existing or not, if not, use the default "Output/Dynamic_quat" folder===		
cd $Configuration_location
Dyn_quat_output_location=`tac $Configuration_file | grep -m 1 '^ *Dyn_quat_output_location *=' | awk -F '"' '{printf $2}'`
if [ ! -d "$Dyn_quat_output_location" ]; then
	Dyn_quat_output_location="$Dock_main_location/Output/Dynamic_quat"
	echo "Use the default output folder which is \"Output/Dynamic_quat/\""
elif [ "$Dyn_quat_output_location" == "." ]; then
	Dyn_quat_output_location=$Configuration_location
else
	# Force the path to be a standard format of absolute path 	
	Dyn_quat_output_location=`cd $Dyn_quat_output_location;pwd`
fi
cd $Dock_main_location

#===Creating new Scilab file in order to run dynamic model in Xcos environment===
#---Check the parameter_loader file---		
cd $Configuration_location
if [ -f "$Dyn_quat_para_setting" ]; then
	if [ "`echo "$Dyn_quat_para_setting" | awk -F / '{print $2}'`" == "" ]; then
		Dyn_quat_para_setting=$Configuration_location/$Dyn_quat_para_setting
	else
		Dyn_quat_para_setting=`cd $(dirname $Dyn_quat_para_setting);pwd`"/"$(basename $Dyn_quat_para_setting)	
	fi
else
	echo "Parameters loader file for AOCS module not found!!"
	echo "Exit the AOCS"
	exit 0
fi	

#---Check the Dyn_quat_para_setting---
if [ ! -f "$Dyn_quat_para_setting" ]; then
	echo "Dyn_quat_para_setting not found!!"
	echo "Exit the AOCS module"
	exit 0
else #---Copy the file from "Input/Dyn_quat" (or specified folder) folder to "AOCS/Inputs" folder---
	cp -f $Dyn_quat_para_setting $Dock_main_location/Module/Simulation/AOCS/Inputs/SatParameters.sce
fi

#---Check the Dyn_quat_seq_inputs_file---
echo $Dyn_quat_seq_inputs_file
if [ ! -f "$Dyn_quat_seq_inputs_file" ]; then
	echo "Dyn_quat_seq_inputs_file not found!!"
	echo "Exit the AOCS module"
	exit 0
else #---Copy the file from "Input/Dyn_quat" (or specified folder) folder to "AOCS/Inputs" folder---
	echo "Load AOCS sequence inputs from file..."
	sed -n '/META_STOP/,$p' "$Dyn_quat_seq_inputs_file" | tail -n +3 > $Dock_main_location/Module/Simulation/AOCS/Inputs/Seq_inputs_temp
fi
cd $Dock_main_location

#---Create a temporary .sce file in order to execute AOCS module automatically---
cd Module/Simulation/AOCS/
Current_location=`pwd`	
echo "Creating new Scilab .sce file......"
{
	echo "clear"
	echo "clc"
	echo ""	
	echo "//===== Load all functions defined for Xcos ====="
	echo "getd('$Current_location');"
	echo ""
	echo "//===== Load Satellite parameters ====="
	echo "exec('$Current_location' + '/Inputs/SatParameters.sce');"
	echo ""
	echo "//===== Load Modes selection ====="
	echo "exec('$Current_location' + '/Modes_loader.sce');"
	echo ""
	echo "//===== Execute the Xcos ====="
	echo "importXcosDiagram('$Current_location' + '/Birdy_Dynamics_Control.zcos');"
	echo "typeof(scs_m); //The diagram data structure"
	echo "scs_m.props.context;"
	echo "xcos_simulate(scs_m, 4);"
	echo ""
	echo "//===== Load the result of Xcos into Scilab workspace ====="
	echo "BIRDY_ATT;"
	echo ""
	echo "//===== Creating CIC file for VTS ====="
	echo "Xcos2CIC_quat( strtod( [Seq_data(1,1), Seq_data(1,2)] ), BIRDY_ATT.values, BIRDY_ATT.time, '$Satellite_name_sce', '$Satellite_REF_FRAME_B', '$Dyn_quat_output_location/$Satellite_name_sce-quaternion-$Date.txt');"
	echo ""
	echo "//===== Exit for Scilab ====="
	echo "exit;" 
} > $Satellite_name_sce-AOCS-$Date.sce
echo "New .sce file has been created."
echo "File name: $Satellite_name_sce-AOCS-$Date.sce"
echo "" 		
echo "Executing the Scilab/Xcos......"
#---Send a title into Log file---
{ echo "===AOCS Scilab===" ; } >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log
#---Execute Scilab---
scilab-adv-cli  -f $Satellite_name_sce-AOCS-$Date.sce -nb >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log

if [ $Keep_temp_file == "False" ]; then
	rm -f Inputs/SatParameters.sce
	rm -f Inputs/Seq_inputs_temp
	rm -f $Satellite_name_sce-AOCS-$Date.sce
fi

echo "New Quarernion CIC file was created."
echo "File name is: $Satellite_name_sce-quaternion-$Date.txt"

#---Put the Easy-quaternion file name into "Check_result.tmp"
{ echo "New_quat = \"$Dyn_quat_output_location/$Satellite_name_sce-quaternion-$Date.txt\" by \"PRODQUAT\"" ; } >> $Dock_main_location/Module/Tmp/Check_result.tmp

