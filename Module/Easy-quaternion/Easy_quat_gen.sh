#!/bin/bash
# File name: Easy_quat_gen.sh
# Version of DOCK: 1.3
# Final Modified Date: 25/08/2015
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
	time_interval= [$Easy_interval];
	start_MJD    = [$Satellite_start_sce_date $Satellite_start_sce_sec];
	end_MJD      = [$Satellite_end_sce_date $Satellite_end_sce_sec];

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
Date=`tac $Check_result | grep -m 1 '^ *Date *=' | awk -F '"' '{printf $2}'`
Scenario_file=`tac $Check_result | grep -m 1 '^ *Scenario_name *=' | awk -F '"' '{printf $2}'`
Configuration_file=`tac $Check_result | grep -m 1 '^ *Configuration_name *=' | awk -F '"' '{printf $2}'`
Error_flag=`tac $Check_result | grep -m 1 '^ *Error_flag *=' | awk -F '"' '{printf $2}'`
Seq_inputs_file=`tac $Check_result | grep -m 1 '^ *Seq_inputs_file *=' | awk -F '"' '{printf $2}'`
New_quat=`tac $Check_result | grep -m 1 '^ *New_quat *=' | awk -F '"' '{printf $2}'`
New_VTS_file=`tac $Check_result | grep -m 1 '^ *New_VTS_file *=' | awk -F '"' '{printf $2}'`

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

if [ $Error_flag == "True" ]; then
	#===Send a title into Log file===
	{
		echo "===Easy quat==="
	} >> $Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log


	#===Check if the specific directory is existing or not, if not, use the default "Output/Easy_quat" folder===		
	Easy_quat_output_location=`tac $Configuration_file | grep -m 1 '^ *Easy_quat_output_location *=' | awk -F '"' '{printf $2}'`
	if [ ! -d "$Easy_quat_output_location" ]; then
		Easy_quat_output_location="$Dock_main_location/Output/Easy_quat"
		echo "Use the default output folder which is \"Output/Easy_quat/\"" | tee -a "$Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log"
	else
		#---remove the "/" at the end of path---	
		if [ "${Easy_quat_output_location: -1}" == "/" ]; then
			Easy_quat_output_location=`echo ${Easy_quat_output_location: 0:-1}`
		fi
	fi

	#===Check the index of "Easy_sed_inputs" ===
	if [ $Easy_sed_inputs == "False" ]; then 
		#===Load parameters for easy quaternion function===
		Easy_init_quat=`tac $Scenario_file | grep -m 1 '^ *Easy_init_quat *=' | awk -F '"' '{printf $2}'`
		Easy_interval=`tac $Scenario_file | grep -m 1 '^ *Easy_interval *=' | awk -F '"' '{printf $2}'`
		Easy_ang_vel=`tac $Scenario_file | grep -m 1 '^ *Easy_ang_vel *=' | awk -F '"' '{printf $2}'`
		Easy_mfile_name='Module/Easy-quaternion/Easy-quat-create-'$Date'.m'
		
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
	echo "New_quat = \"$Easy_quat_output_location/Easy-quaternion-$Date.txt\"" 
	} >> Module/Tmp/Check_result.tmp
fi
