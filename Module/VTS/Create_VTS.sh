#!/bin/bash
# File name: Create_VTS.sh
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
PRODVTS=`grep 'PRODVTS' $Check_result | awk -F '"' '{printf $2}'`
if [ "$PRODVTS" == "True" ]; then
	echo  -e "\033[33m===VTS generator module===\033[0m" | tee -a "$Dock_main_location/Output/Log/DEBUG_Log/Log-$Date.log"
else
	exit
fi


if [ "$New_quat" == "" ]; then
	New_quat=`tac $Configuration_file | grep -m 1 '^ *Satellite_quaternion *=' | awk -F '"' '{printf $2}'`
	echo "No new attitude data found, use the file defined in Configuration file."
fi

if [ "$New_trajectory" == "" ]; then
	New_trajectory=`tac $Configuration_file | grep -m 1 '^ *Satellite_position *=' | awk -F '"' '{printf $2}'`
	echo "No new postion data found, use the file defined in Configuration file."
fi

#===Load parameters from Scenario file===
Keep_temp_file=`tac $Scenario_file | grep -m 1 '^ *Keep_temp_file *=' | awk -F '"' '{printf $2}'`
Satellite_name_sce=`tac $Configuration_file | grep -m 1 '^ *Satellite_name *=' | awk -F '"' '{printf $2}'`
Satellite_parent_sce=`tac $Configuration_file | grep -m 1 '^ *Satellite_parentpath *=' | awk -F '"' '{printf $2}'`
Satellite_3ds_sce=`tac $Configuration_file | grep -m 1 '^ *Satellite_3ds *=' | awk -F '"' '{printf $2}'`
Satellite_Axes=`tac $Configuration_file | grep -m 1 '^ *Satellite_Axes *=' | awk -F '"' '{printf $2}'`
Satellite_start_sce_date=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_start *=' | awk -F '"' '{printf $2}' | awk '{printf $1}'`
Satellite_start_sce_sec=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_start *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`  
Satellite_end_sce_date=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_end *=' | awk -F '"' '{printf $2}' | awk '{printf $1}'`
Satellite_end_sce_sec=`tac $Scenario_file | grep -m 1 '^ *Simulation_time_end *=' | awk -F '"' '{printf $2}' | awk '{printf $2}'`
VTS_Body_ParentPath=`tac $Configuration_file | grep -m 1 '^ *Satellite_parentpath *=' | awk -F '"' '{printf $2}' | awk -F / '{print $1}'`
VTS_Body_Name=`tac $Configuration_file | grep -m 1 '^ *Satellite_parentpath *=' | awk -F '"' '{printf $2}' | awk -F / '{print $2}'`
VTS_Body_Axes=$VTS_Body_Name"_Axes"

#===Check if the specific directory is existing or not, if not, use the default "Output/VTS_gen" folder===		
VTS_output_location=`tac $Configuration_file | grep -m 1 '^ *VTS_output_location *=' | awk -F '"' '{printf $2}'`
if [ ! -d "$VTS_output_location" ]; then
	VTS_output_location="$Dock_main_location/Output/VTS_gen"
	echo "Use the default output folder which is \"Output/VTS_gen/\""
else
	#---remove the "/" at the end of path---	
	if [ "${VTS_output_location: -1}" == "/" ]; then
		VTS_output_location=`echo ${VTS_output_location: 0:-1}`
	fi
fi

#===Creating new VTS project file (.xml)===
echo -e "Creating the VTS project......"
		
cat > $VTS_output_location/VTS-$Date.vts <<EOF
<?xml version="1.0" encoding="UTF-8"?>
<Project Revision="4436">
 <General Name="" StartDateTime="$Satellite_start_sce_date $Satellite_start_sce_sec" EndDateTime="$Satellite_end_sce_date $Satellite_end_sce_sec"/>
 <MetaData Description=""/>
 <StartOptions TimeRatio="1" SysTimeSynced="0" Paused="0" Looped="0" Minimized="0" Hidden="0" AutoClosed="0"/>
 <BrokerOptions WindowMode="Undocked" Collapsed="0" AlwaysOnTop="0" XPos="20" YPos="690" Width="1600" Height="280" ActiveTab="3"/>
 <TimelineOptions>
  <TimelineScenario Name="Scenario" Pos="0" Size="35"/>
 </TimelineOptions>
 <ToBeUsedApps>
  <Application Name="Celestia" Id="0"/>
  <Application Name="Celestia" Id="1"/>
 </ToBeUsedApps>
 <Entities>
  <Body Name="$VTS_Body_Name" ParentPath="$VTS_Body_ParentPath">
   <Prop2d>
    <SymbolFile Name=""/>
   </Prop2d>
   <EphemerisMode Mode="Default"/>
  </Body>
  <Satellite Name="$Satellite_name_sce" ParentPath="$Satellite_parent_sce">
   <CommonProp>
    <OrbitPath Color="1 0.471504 0"/>
   </CommonProp>
   <Prop2d>
    <SymbolFile Name=""/>
   </Prop2d>
   <Component Name="$Satellite_name_sce">
    <Graphics3d>
     <File3ds Name="$Satellite_3ds_sce"/>
     <Radius Value="1"/>
     <LightSensitive Value="1"/>
     <Use3dsCoords Value="0" MeshScale="1"/>
     <RotationCenter X="0" Y="0" Z="0"/>
    </Graphics3d>
    <Geometry>
     <Position>
      <Value>
       <File Name="$New_trajectory"/>
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
    <Command Str="CMD PROP CameraDesc bodyfixed &quot;$VTS_Body_ParentPath/$VTS_Body_Name/$VTS_Body_Axes&quot; nil -6.1026e-10 6.1026e-10 -6.1026e-10 -0.4247079 -0.8204734 -0.3398512 0.1759197 0.506789088249207"/>
    <Command Str="CMD PROP SelectObject $Satellite_parent_sce"/>
    <Command Str="CMD PROP AmbientLight 1"/>
    <Command Str="CMD STRUCT BodyScale &quot;$Satellite_parent_sce&quot; 0.4"/>
    <Command Str="CMD STRUCT Eme2000AxesVisible &quot;$Satellite_parent_sce&quot; true"/>
    <Command Str="CMD STRUCT SatelliteScale &quot;$Satellite_parent_sce/$Satellite_name_sce&quot; 4.96356e+06"/>
    <Command Str="CMD STRUCT FrameAxesVisible &quot;$Satellite_parent_sce/$Satellite_name_sce&quot; false"/>
   </AppState>
   <AppState Id="1">
    <Command Str="CMD PROP AntialiasingSamples 20"/>
    <Command Str="CMD PROP WindowGeometry 0 0 800 640"/>
    <Command Str="CMD PROP CameraDesc bodyfixed &quot;$Satellite_parent_sce/$Satellite_Axes&quot; nil -1.35016058381724e-09 1.35016058381724e-09 -1.35016058381724e-09 0.4247082 0.8204732 0.3398512 -0.1759199 0.214830741286278"/>
    <Command Str="CMD PROP SelectObject $Satellite_parent_sce/$Satellite_Axes"/>
    <Command Str="CMD PROP AmbientLight 1"/>
    <Command Str="CMD STRUCT SatelliteScale &quot;$Satellite_parent_sce/$Satellite_name_sce&quot; 3"/>
    <Command Str="CMD STRUCT OrbitWindow &quot;$Satellite_parent_sce/$Satellite_name_sce&quot; 0.5 0.5"/>
   </AppState>
  </Instant>
 </States>
</Project>
EOF
echo -e "\e[92mNew VTS project file was created.\e[0m"
echo -e "\e[92mFile name is: VTS-$Date.vts\e[0m"
echo ""

#---Put the New VTS project name into "Check_result.tmp"
{ echo "New_VTS_file = \"$VTS_output_location/VTS-$Date.vts\"" ; } >> Module/Tmp/Check_result.tmp
