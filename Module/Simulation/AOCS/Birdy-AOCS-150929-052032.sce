clear
clc

//===== Load all functions defined for Xcos =====
getd('/home/birdy/Software/DOCK_v1-4/Module/Simulation/AOCS');

//===== Load Satellite parameters =====
exec(/home/birdy/Software/DOCK_v1-4/Module/Simulation/AOCS + '/Inputs/SatParameters.sce');

//===== Load Modes selection =====
exec(/home/birdy/Software/DOCK_v1-4/Module/Simulation/AOCS + '/Modes_loader.sce');

//===== Execute the Xcos =====
importXcosDiagram(/home/birdy/Software/DOCK_v1-4/Module/Simulation/AOCS + '/Birdy_Dynamics_Control.zcos');
typeof(scs_m) //The diagram data structure
scs_m.props.context;
xcos_simulate(scs_m, 4);

//===== Load the result of Xcos into Scilab workspace =====
BIRDY_ATT;

//===== Creating CIC file for VTS =====
Xcos2CIC_quat( strtod( [Seq_data(1,1), Seq_data(1,2)] ), BIRDY_ATT.values, BIRDY_ATT.time, 'Birdy', 'SC_BODY_1', '/home/birdy/Software/DOCK_v1-4/Output/Dynamic_quat/Birdy-quaternion-150929-052032.txt');

//===== Exit for Scilab =====
exit;
