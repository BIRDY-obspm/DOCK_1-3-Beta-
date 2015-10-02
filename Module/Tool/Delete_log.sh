#!/bin/bash
# File name: Delet_log.sh
# Version: 1.4
# Final Modified Date: 26/08/2015
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

Scenario_file=`tac $Check_result | grep -m 1 '^ *Scenario_name *=' | awk -F '"' '{printf $2}'`
DEBUG_Log=`tac $Check_result | grep -m 1 '^ *DEBUG_Log *=' | awk -F '"' '{printf $2}'`

#===Load parameters from Scenario & Configuration files===
Keep_debug_file=`tac $Scenario_file | grep -m 1 '^ *Keep_debug_file *=' | awk -F '"' '{printf $2}'`

if [ $Keep_debug_file == "False" ]; then
	echo ""
	cd Output/Log/DEBUG_Log/
	rm -f $DEBUG_Log
	echo  -e "\033[91mLog file has been deleted\033[0m"
fi
