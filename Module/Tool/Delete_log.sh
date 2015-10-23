#!/bin/bash
# File name: Delet_log.sh
# Version: 1.4
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

Scenario_file=`tac $Check_result | grep -m 1 '^ *Scenario_name *=' | awk -F '"' '{printf $2}'`
DEBUG_Log=`tac $Check_result | grep -m 1 '^ *DEBUG_Log *=' | awk -F '"' '{printf $2}'`

#===Load parameters from Scenario & Configuration files===
Keep_debug_file=`tac $Scenario_file | grep -m 1 '^ *Keep_debug_file *=' | awk -F '"' '{printf $2}'`

if [ $Keep_debug_file == "False" ]; then
	echo ""
	cd Output/Log/DEBUG_Log/
	rm -f $DEBUG_Log
	echo "Log file has been deleted"
fi
