#!/bin/bash
# File name: Create_VTS.sh
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
PRODVTS=`grep 'PRODVTS' $Check_result | awk -F '"' '{printf $2}'`
if [ "$PRODVTS" == "True" ]; then
	echo ""
	echo "===VTS generator module===" | tee -a "$Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log"
else
	exit
fi

#===Find the correct sequence of "Madule Selection" in Scenario file===
#---how many same name files in "Check_result"---
New_quat_num=`grep '^ *New_quat *=' $Check_result | wc -l`
New_traj_num=`grep '^ *New_traj *=' $Check_result | wc -l`

#---Put the final search result into variable--- 
New_quat=`tac $Check_result | grep -m 1 '^ *New_quat *=' | awk -F '"' '{printf $2}'`
New_traj=`tac $Check_result | grep -m 1 '^ *New_traj *=' | awk -F '"' '{printf $2}'`

#---Check the situation of existing files listed in "Check_result" (empty, one, or many)---//26082015
if [ "$New_quat" == "" ]; then
	New_quat=`tac $Configuration_file | grep -m 1 '^ *Satellite_quaternion *=' | awk -F '"' '{printf $2}'`
	echo "No new attitude data found, use the file defined in Configuration file."
elif [ "$New_quat_num" -gt 1 ]; then
	check_count=1
	previous_num=1000	
	until [ "$check_count" -gt "$New_quat_num" ]
	do
		Search_target=`grep -m $check_count '^ *New_quat *=' $Check_result | tail -n 1 | awk -F '"' '{printf $4}'`
		current_num=`tac $Scenario_file | sed -n "1,/^ *$Search_target */p" | wc -l`		
		if [ "$current_num" -lt "$previous_num" ]; then
			previous_num=$current_num
			New_quat=`grep -m $check_count '^ *New_quat *=' $Check_result | tail -n 1 | awk -F '"' '{printf $2}'`
		fi
		(( check_count += 1 )) 
	done
fi

if [ "$New_traj" == "" ]; then
	New_traj=`tac $Configuration_file | grep -m 1 '^ *Satellite_position *=' | awk -F '"' '{printf $2}'`
	echo "No new postion data found, use the file defined in Configuration file."
elif [ "$New_traj_num" -gt 1 ]; then
	check_count=1
	previous_num=1000	
	until [ "$check_count" -gt "$New_traj_num" ]
	do
		Search_target=`grep -m $check_count '^ *New_traj *=' $Check_result | tail -n 1 | awk -F '"' '{printf $4}'`
		current_num=`tac $Scenario_file | sed -n "1,/^ *$Search_target */p" | wc -l`		
		if [ "$current_num" -lt "$previous_num" ]; then
			previous_num=$current_num
			New_traj=`grep -m $check_count '^ *New_traj *=' $Check_result | tail -n 1 | awk -F '"' '{printf $2}'`
		fi
		(( check_count += 1 )) 
	done
fi
#===Load parameters from Scenario file===
Keep_temp_file=`tac $Scenario_file | grep -m 1 '^ *Keep_temp_file *=' | awk -F '"' '{printf $2}'`
Sec_satellite_name=`tac $Configuration_file | grep -m 1 '^ *Satellite_name *=' | awk -F '"' '{printf $2}'`
Sec_satellite_parent=`tac $Configuration_file | grep -m 1 '^ *Satellite_parentpath *=' | awk -F '"' '{printf $2}'`
Sec_satellite_3ds=`tac $Configuration_file | grep -m 1 '^ *Satellite_3ds *=' | awk -F '"' '{printf $2}'`
Sec_satellite_axes=`tac $Configuration_file | grep -m 1 '^ *Satellite_Axes *=' | awk -F '"' '{printf $2}'`
Sec_start=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_start *=' | awk -F '"' '{printf $2}'`  
Sec_end=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_end *=' | awk -F '"' '{printf $2}'`
Sec_body_parent=`tac $Configuration_file | grep -m 1 '^ *Satellite_parentpath *=' | awk -F '"' '{printf $2}' | awk -F / '{print $1}'`
Sec_body_name=`tac $Configuration_file | grep -m 1 '^ *Satellite_parentpath *=' | awk -F '"' '{printf $2}' | awk -F / '{print $2}'`
Sec_body_axes=$Sec_body_name"_Axes"

#===Check if the specific directory is existing or not, if not, use the default "Output/VTS_gen" folder===		
cd $Configuration_location
VTS_output_location=`tac $Configuration_file | grep -m 1 '^ *VTS_output_location *=' | awk -F '"' '{printf $2}'`
if [ ! -d "$VTS_output_location" ]; then
	VTS_output_location="$Dock_main_location/Output/VTS_gen"
	echo "Use the default output folder which is \"Output/VTS_gen/\""
elif [ "$VTS_output_location" == "." ]; then
	VTS_output_location=$Configuration_location
else
	# Force the path to be a standard format of absolute path 	
	VTS_output_location=`cd $VTS_output_location;pwd`
fi
cd $Dock_main_location
#===Creating new VTS project file (.xml)===

#---Check the flag of "Keep_Apps_setting"---
Keep_Apps_setting=`tac $Configuration_file | grep -m 1 '^ *Keep_Apps_setting *=' | awk -F '"' '{printf $2}'`
VTS_project=`tac $Configuration_file | grep -m 1 '^ *VTS_project_file *=' | awk -F '"' '{printf $2}'`

if [ "$Keep_Apps_setting" == "True" ] && [ -f "$VTS_project" ]; then

	echo "Keep original setting of .vts project, only updating changed parts..."	
	VTS_start=`grep 'StartDateTime' $VTS_project | cut -d '"' -f 4` 
	VTS_end=`grep 'EndDateTime' $VTS_project | cut -d '"' -f 6` 
	VTS_body_name=`grep '<Body Name=' $VTS_project | cut -d '"' -f 2`
	VTS_body_parent=`grep '<Body Name=' $VTS_project | cut -d '"' -f 4`
	VTS_satellite_name=`grep '<Satellite Name' $VTS_project | cut -d '"' -f 2`
	VTS_satellite_parent=`grep '<Satellite Name' $VTS_project | cut -d '"' -f 4`
	VTS_satellite_3ds=`sed -n "/<Component Name=\"$VTS_satellite_name\"/,/\/Graphics3d/p" $VTS_project | head -n 3 | grep -m 1 '<File3ds Name=' | cut -d '"' -f 2`
	VTS_satellite_quaternion=`sed -n '/Satellite Name=/,/\/Satellite/p' $VTS_project | sed -n '/Quaternion/,/\/Quaternion/p' | grep '<File Name=' | cut -d '"' -f 2`
	VTS_satellite_position=`sed -n '/Satellite Name=/,/\/Satellite/p' $VTS_project | sed -n '/Position/,/\/Position/p' | grep '<File Name=' | cut -d '"' -f 2`
	
	# To replace the "/" in the path with "\/"
	VTS_3ds_mod=`echo "$VTS_satellite_3ds" | awk -F / '{for(i=1; i<NF; i++) printf $i"\/"; printf $NF}'`
	VTS_pos_mod=`echo "$VTS_satellite_position" | awk -F / '{for(i=1; i<NF; i++) printf $i"\/"; printf $NF}'`
	VTS_qua_mod=`echo "$VTS_satellite_quaternion" | awk -F / '{for(i=1; i<NF; i++) printf $i"\/"; printf $NF}'`
	New_3ds_mod=`echo "$Sec_satellite_3ds" | awk -F / '{for(i=1; i<NF; i++) printf $i"\/"; printf $NF}'`
	New_pos_mod=`echo "$New_traj" | awk -F / '{for(i=1; i<NF; i++) printf $i"\/"; printf $NF}'`
	New_qua_mod=`echo "$New_quat" | awk -F / '{for(i=1; i<NF; i++) printf $i"\/"; printf $NF}'`
	
	sed -e "
		s/StartDateTime=\"$VTS_start\" EndDateTime=\"$VTS_end\"/StartDateTime=\"$Sec_start\" EndDateTime=\"$Sec_end\"/g
		s/Body Name=\"$VTS_body_name\" ParentPath=\"$VTS_body_parent\"/Body Name=\"$Sec_body_name\" ParentPath=\"$Sec_body_parent\"/g
		s/Satellite Name=\"$VTS_satellite_name\" ParentPath=\"$VTS_body_parent\/$VTS_body_name\"/Satellite Name=\"$Sec_satellite_name\" ParentPath=\"$Sec_body_parent\/$Sec_body_name\"/g
		s/Component Name=\"$VTS_satellite_name\"/Component Name=\"$Sec_satellite_name\"/g
		s/File3ds Name=\"$VTS_3ds_mod\"/File3ds Name=\"$New_3ds_mod\"/g
		s/File Name=\"$VTS_pos_mod\"/File Name=\"$New_pos_mod\"/g
		s/File Name=\"$VTS_qua_mod\"/File Name=\"$New_qua_mod\"/g" $VTS_project > $VTS_output_location/VTS-$Date.vts

else
	echo "Create a new .vts project..."		
cat > $VTS_output_location/VTS-$Date.vts <<EOF
<?xml version="1.0" encoding="UTF-8"?>
<Project Revision="4436">
 <General Name="" StartDateTime="$Sec_start" EndDateTime="$Sec_end"/>
 <MetaData Description=""/>
 <StartOptions TimeRatio="1" SysTimeSynced="0" Paused="0" Looped="0" Minimized="0" Hidden="0" AutoClosed="0"/>
 <BrokerOptions WindowMode="Undocked" Collapsed="0" AlwaysOnTop="0" XPos="20" YPos="690" Width="1600" Height="280" ActiveTab="3"/>
 <TimelineOptions>
  <TimelineScenario Name="Scenario" Pos="0" Size="35"/>
 </TimelineOptions>
 <ToBeUsedApps>
  <Application Name="Celestia" Id="0"/>
  <Application Name="2dWin" Id="1"/>
 </ToBeUsedApps>
 <Entities>
  <Body Name="$Sec_body_name" ParentPath="$Sec_body_parent">
   <Prop2d>
    <SymbolFile Name=""/>
   </Prop2d>
   <EphemerisMode Mode="Default"/>
  </Body>
  <Satellite Name="$Sec_satellite_name" ParentPath="$Sec_body_parent/$Sec_body_name">
   <CommonProp>
    <OrbitPath Color="1 0.471504 0"/>
   </CommonProp>
   <Prop2d>
    <SymbolFile Name=""/>
   </Prop2d>
   <Component Name="$Sec_satellite_name">
    <Graphics3d>
     <File3ds Name="$Sec_satellite_3ds"/>
     <Radius Value="1"/>
     <LightSensitive Value="1"/>
     <Use3dsCoords Value="0" MeshScale="1"/>
     <RotationCenter X="0" Y="0" Z="0"/>
    </Graphics3d>
    <Geometry>
     <Position>
      <Value>
       <File Name="$New_traj"/>
      </Value>
     </Position>
     <Orientation>
      <Quaternion>
       <Value>
	<File Name="$New_quat"/>
       </Value>
      </Quaternion>
     </Orientation>
    </Geometry>
   </Component>
   <Events/>
  </Satellite>
 </Entities>
 <Events/>
 <States>
  <Instant Time="0" Label="Initial state">
   <AppState Id="0">
    <Command Str="CMD PROP WindowGeometry 860 0 800 640"/>
    <Command Str="CMD PROP CameraDesc bodyfixed &quot;$Sec_body_parent/$Sec_body_name/$Sec_body_axes&quot; nil -6.1026e-10 6.1026e-10 -6.1026e-10 -0.4247079 -0.8204734 -0.3398512 0.1759197 0.506789088249207"/>
    <Command Str="CMD PROP SelectObject $Sec_body_parent/$Sec_body_name"/>
    <Command Str="CMD PROP AmbientLight 1"/>
    <Command Str="CMD STRUCT BodyScale &quot;$Sec_body_parent/$Sec_body_name&quot; 0.4"/>
    <Command Str="CMD STRUCT Eme2000AxesVisible &quot;$Sec_body_parent/$Sec_body_name&quot; true"/>
    <Command Str="CMD STRUCT SatelliteScale &quot;$Sec_body_parent/$Sec_body_name/$Sec_satellite_name&quot; 4.96356e+06"/>
    <Command Str="CMD STRUCT FrameAxesVisible &quot;$Sec_body_parent/$Sec_body_name/$Sec_satellite_name&quot; false"/>
   </AppState>
   <AppState Id="1">
    <Command Str="CMD PROP WindowGeometry 0 0 800 470"/>
    <Command Str="CMD STRUCT OrbitWindow &quot;$Sec_body_parent/$Sec_body_name/$Sec_satellite_name&quot; 0.5 0.5"/>
   </AppState>
  </Instant>
 </States>
</Project>
EOF
fi

echo "New VTS project file was created."
echo "File name is: VTS-$Date.vts"

#---Put the New VTS project name into "Check_result.tmp"
{ echo "New_VTS_file = \"$VTS_output_location/VTS-$Date.vts\"" ; } >> Module/Tmp/Check_result.tmp
