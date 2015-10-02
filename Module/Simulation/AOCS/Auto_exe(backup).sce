clear
clc

//===== Load all functions defined for Xcos =====
getd(pwd());

//===== Load Satellite parameters =====
exec(pwd() + '/Inputs/SatParameters.sce');

//===== Load Modes selection =====
exec(pwd() + '/Modes_loader.sce'); 

//===== Execute the Xcos =====
importXcosDiagram(pwd() + '/Birdy_Dynamics_Control.zcos');
typeof(scs_m); //The diagram data structure
scs_m.props.context;
xcos_simulate(scs_m, 4);

//===== Load the result of Xcos into Scilab workspace =====
BIRDY_ATT;

//===== Creating CIC file for VTS =====
Xcos2CIC_quat( strtod( [Seq_data(1,1), Seq_data(1,2)] ), BIRDY_ATT.values, BIRDY_ATT.time, 'BIRDY', 'SC_BODY_1', pwd() + '/Outputs/' + date() + '-CIC.txt');

//===== Exit for Scilab =====
exit;
