#!/bin/bash
# File name: Easy_quat_gen.sh
# Final Modified Date: 07/09/2015
# 
# Author: Hao-Chih,Lin (Jim,Lin)
# Email : F44006076@gmail.com  
#
#==================================================
#===Function for creating easy quaternion m file===
#==================================================
#Input:
#$1: File name of m-file
#$2: The location of "CIC_quat_gen" function
#$3: File name of Easy quaternion CIC file
#$4: If the sequence inputs will be used or not (T/F)
#$5: If the sequence inputs mode was selected, put the seq_inputs file name, otherwise enter NULL

function Easy_quaternion_m_file()
{
echo ""
echo -e "Creating the Easy quaternion m-file for Octave......"
		
cat > $1 <<EOF
clear
fclose('all');
clc

% ===cd to specific folder===
cd $2

% ===user data===
ORIGINATOR = 'BIRDY AOCS TEAM';
CIC_AEM_VERS = 1.0; 
OBJECT_NAME = '$Satellite_name_sce'; 
OBJECT_ID = '$Satellite_name_sce';
REF_FRAME_A   = '$Satellite_REF_FRAME_A'; 
REF_FRAME_B   = '$Satellite_REF_FRAME_B';
ATTITUDE_DIR = '$Satellite_ATTITUDE_DIR';
ATTITUDE_TYPE = 'QUATERNION';
TIME_SYSTEM = '$Satellite_TIME_SYSTEM'; 
file_name='$3';
CREATION_DATE  = strftime("%Y-%m-%dT%X", localtime(time()) );

% ===create titles===
delimiter1='META_START';
delimiter2='META_STOP';
l1='CIC_AEM_VERS = ';
l2='CREATION_DATE = ';
l3='ORIGINATOR = ';
l5='OBJECT_NAME = ';
l6='OBJECT_ID = ';
l8='REF_FRAME_A = ';
l81='REF_FRAME_B = ';
l9='ATTITUDE_DIR = ';
l10='TIME_SYSTEM = ';
l11='ATTITUDE_TYPE = ';

% ===Write titles into file===
fichier=fopen(file_name,'w');
    fprintf(fichier,'%s%3.1f\n%s%s\n%s%s\n\n%s\n\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n%s\n\n',...
        l1,CIC_AEM_VERS,l2,CREATION_DATE,l3,ORIGINATOR,delimiter1,l5,...
        OBJECT_NAME,l6,OBJECT_ID,l8,REF_FRAME_A,l81,REF_FRAME_B,l9,...
        ATTITUDE_DIR,l10,TIME_SYSTEM,l11,ATTITUDE_TYPE,delimiter2);
fclose(fichier);

if ( '$4' == 'F' )
	% ===Run the CIC_quat_gen function===
	initial_quat = [$Easy_init_quat];
	angular_vel  = [$Easy_ang_vel];
	time_interval= [$step_size];
	start_MJD    = [$start_date $start_sec];
	end_MJD      = [$end_date $end_sec];

	disp('processing...');
	[MJD_date, MJD_sec, Q]=CIC_quat_gen( initial_quat, angular_vel, time_interval, start_MJD, end_MJD );
else
	disp('processing...');	
	[MJD_date, MJD_sec, Q]=CIC_quat_gen_seq_inputs('$5');
endif


% ===Write quaternion data into file===
s=size(MJD_date);
for i=1:s(1)
    fichier=fopen(file_name,'a');
    fprintf(fichier,'\n%5d %9.3f %8.6f %8.6f %8.6f %8.6f',MJD_date(i),MJD_sec(i), Q(i,1),Q(i,2),Q(i,3),Q(i,4));
    fclose(fichier);
end

disp('Success!!');

exit
EOF
echo -e "\e[92mNew Easy quaternion m-file was created.\e[0m"
echo -e "\e[92mFile name is: $1\e[0m"
echo ""
}


#===================================================
#=======================Program=====================
#===================================================
#===Load "Date" infromation from "Check_result.tmp" file===
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
Seq_inputs_file=`tac $Check_result | grep -m 1 '^ *Seq_inputs_file *=' | awk -F '"' '{printf $2}'`
Dock_main_location=`pwd`
#===Check the need of this module===
EASYQUAT=`grep 'EASYQUAT' $Check_result | awk -F '"' '{printf $2}'`
if [ "$EASYQUAT" == "True" ]; then
	echo  -e "\033[33m===Easy quaternion module===\033[0m" | tee -a "$Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log"
else
	exit
fi
#===Load parameters from Scenario & Configuration files===
Easy_sed_inputs=`tac $Scenario_file | grep -m 1 '^ *Easy_sed_inputs *=' | awk -F '"' '{printf $2}'`
Keep_temp_file=`tac $Scenario_file | grep -m 1 '^ *Keep_temp_file *=' | awk -F '"' '{printf $2}'`
Satellite_name_sce=`tac $Configuration_file | grep -m 1 '^ *Satellite_name *=' | awk -F '"' '{printf $2}'`
Satellite_REF_FRAME_A=`tac $Configuration_file | grep -m 1 '^ *Satellite_ref_frame_A *=' | awk -F '"' '{printf $2}'`
Satellite_REF_FRAME_B=`tac $Configuration_file | grep -m 1 '^ *Satellite_ref_frame_B *=' | awk -F '"' '{printf $2}'`
Satellite_ATTITUDE_DIR=`tac $Configuration_file | grep -m 1 '^ *Satellite_attitude_dir *=' | awk -F '"' '{printf $2}'`
Satellite_TIME_SYSTEM=`tac $Configuration_file | grep -m 1 '^ *Satellite_time_system *=' | awk -F '"' '{printf $2}'`
Satellite_start_sce_date=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_start *=' | awk -F '"' '{printf $2}' | awk '{printf $1}'`
Satellite_start_sce_sec=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_start *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`  
Satellite_end_sce_date=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_end *=' | awk -F '"' '{printf $2}' | awk '{printf $1}'`
Satellite_end_sce_sec=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_end *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`
Simulation_step_size=`tac $Scenario_file | grep -m 1 '^ *Simulation_step_size *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`

Easy_quat_start_date=`tac $Scenario_file | grep -m 1 '^ *Easy_quat_start *=' | awk -F '"' '{printf $2}' | awk '{printf $1}'`
Easy_quat_start_sec=`tac $Scenario_file | grep -m 1 '^ *Easy_quat_start *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`
Easy_quat_end_date=`tac $Scenario_file | grep -m 1 '^ *Easy_quat_end *=' | awk -F '"' '{printf $2}' | awk '{printf $1}'`
Easy_quat_end_sec=`tac $Scenario_file | grep -m 1 '^ *Easy_quat_end *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`
Easy_quat_step=`tac $Scenario_file | grep -m 1 '^ *Easy_quat_step *=' | awk -F '"' '{printf $2}'`
#===Send a title into Log file===
{
	echo "===Easy quat==="
} >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log

#===Check if the specific directory is existing or not, if not, use the default "Output/Easy_quat" folder===		
cd $Configuration_location	
Easy_quat_output_location=`tac $Configuration_file | grep -m 1 '^ *Easy_quat_output_location *=' | awk -F '"' '{printf $2}'`
if [ ! -d "$Easy_quat_output_location" ]; then
	Easy_quat_output_location="$Dock_main_location/Output/Easy_quat"
	echo "Use the default output folder which is \"Output/Easy_quat/\"" | tee -a "$Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log"
elif [ "$Easy_quat_output_location" == "." ]; then
	Easy_quat_output_location=$Configuration_location	
else
	# Force the path to be a standard format of absolute path 	
	Easy_quat_output_location=`cd $Easy_quat_output_location;pwd`		
fi
cd $Dock_main_location

#===Check the index of "Easy_sed_inputs" ===
if [ $Easy_sed_inputs == "False" ]; then 
	#===Load parameters for easy quaternion function===
	Easy_init_quat=`tac $Scenario_file | grep -m 1 '^ *Easy_init_quat *=' | awk -F '"' '{printf $2}'`
	Easy_ang_vel=`tac $Scenario_file | grep -m 1 '^ *Easy_ang_vel *=' | awk -F '"' '{printf $2}'`
	Easy_mfile_name='Module/Easy-quaternion/Easy-quat-create-'$Date'.m'
	
	#===Check if the definition of parameters is correct or not===
	Error_count=0
	#---Start date---
	if [ "$Easy_quat_start_date" == "" ]; then
		start_date=$Satellite_start_sce_date
	else
		start_date=$Easy_quat_start_date
	fi
	if echo $start_date | egrep -q '^[0-9]+$' ; then
		echo "Start date is: $start_date (MJD)"
	else
		echo -e "\033[91mDefinition of 'Start date' is wrong!!\033[0m"
		(( Error_count += 1 ))
	fi
	#---Start sec---
	if [ "$Easy_quat_start_sec" == "" ]; then
		start_sec=$Satellite_start_sce_sec
	else
		start_sec=$Easy_quat_start_sec
	fi
	if echo $start_sec | egrep -q '^[0-9.]+$' ; then
		echo "Start sec is: $start_sec "
	else
		echo -e "\033[91mDefinition of 'Start sec' is wrong!!\033[0m"
		(( Error_count += 1 ))
	fi
	#---End date---
	if [ "$Easy_quat_end_date" == "" ]; then
		end_date=$Satellite_end_sce_date
	else
		end_date=$Easy_quat_end_date
	fi
	if echo $end_date | egrep -q '^[0-9]+$' ; then
		echo "End date is: $end_date (MJD)"
	else
		echo -e "\033[91mDefinition of 'End date' is wrong!!\033[0m"
		(( Error_count += 1 ))
	fi
	#---End sec---
	if [ "$Easy_quat_end_sec" == "" ]; then
		end_sec=$Satellite_end_sce_sec
	else
		end_sec=$Easy_quat_end_sec
	fi
	if echo $end_sec | egrep -q '^[0-9.]+$' ; then
		echo "End sec is: $end_sec "
	else
		echo -e "\033[91mDefinition of 'End sec' is wrong!!\033[0m"
		(( Error_count += 1 ))
	fi
	#---Step size---
	if [ "$Easy_quat_step" == "" ]; then
		step_size=$Simulation_step_size
	else
		step_size=$Easy_quat_step
	fi
	if echo $step_size | egrep -q '^[0-9.]+$' ; then
		echo "Step size is: $step_size (sec)"
	else
		echo -e "\033[91mDefinition of 'Step size' is wrong!!\033[0m"
		(( Error_count += 1 ))
	fi
	#---Result---
	if [ ! "$Error_count" == 0 ]; then
		echo -e "\033[91mThere is(are) $Error_count error(s)!!\033[0m"
		echo -e "Exit the Easy-quaternion module"
		exit 0
	fi

	#---Check the Sat name---
	if [ "$Satellite_name_sce" = "" ]; then
		Satellite_name_sce="Undefined"
	fi
	if [ "$Satellite_REF_FRAME_A" = "" ]; then
		Satellite_REF_FRAME_A="EME2000"
	fi


	#===Call the function for creating new m-fil for Octave in order to generate easy quaternion CIC file===
	Easy_quaternion_m_file $Easy_mfile_name Module/Easy-quaternion/ $Easy_quat_output_location/Easy-quaternion-$Date.txt F Null

	#===Execute the Octave===
	echo "Executing the Octave..."
	octave $Easy_mfile_name >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log
	echo -e "\e[92mNew Easy Quarernion CIC file was created.\e[0m"
	echo -e "\e[92mFile name is: Easy-quaternion-$Date.txt\e[0m"

	if [ $Keep_temp_file == "False" ]; then
		rm -f $Easy_mfile_name
	fi
	
elif [ $Easy_sed_inputs == "True" ]; then
	#---Check the Seq_inputs_file---
	if [ ! -f "$Seq_inputs_file" ]; then
		echo -e "\033[91mSeq_inputs_file not found!!\033[0m"
		echo -e "Exit the Easy-quaternion module"
		exit 0
	fi

	echo -e "\e[92mLoad sequence inputs from file...\e[0m"
	sed -n '/META_STOP/,$p' "$Seq_inputs_file" | tail -n +3 > Module/Easy-quaternion/Tmp-seq-inputs-$Date
	Easy_mfile_name='Module/Easy-quaternion/Easy-quat-create-'$Date'.m'
	#===Call the function for creating new m-fil for Octave in order to generate easy quaternion CIC file===
	Easy_quaternion_m_file $Easy_mfile_name Module/Easy-quaternion/ $Easy_quat_output_location/Easy-quaternion-$Date.txt T Tmp-seq-inputs-$Date

	#===Execute the Octave===
	echo "Executing the Octave..."
	octave $Easy_mfile_name >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log
	echo -e "\e[92mNew Easy Quarernion CIC file was created.\e[0m"
	echo -e "\e[92mFile name is: Easy-quaternion-$Date.txt\e[0m"

	if [ $Keep_temp_file == "False" ]; then
		rm -f $Easy_mfile_name
		rm -f Module/Easy-quaternion/Tmp-seq-inputs-$Date
	fi
fi 
#---Put the Easy-quaternion file name into "Check_result.tmp"
{ 
echo "New_quat = \"$Easy_quat_output_location/Easy-quaternion-$Date.txt\" by \"EASYQUAT\"" 
} >> Module/Tmp/Check_result.tmp
