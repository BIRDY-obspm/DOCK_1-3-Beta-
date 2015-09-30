//===== Load functions for Xcos =====
exec('/home/birdy/Software/DOCK_v1-3/Module/Simulation/AOCS/LeastNormTorque.sci')

exec('/home/birdy/Software/DOCK_v1-3/Module/Simulation/AOCS/NDI_rateControl.sci')

exec('/home/birdy/Software/DOCK_v1-3/Module/Simulation/AOCS/OmegaPrime.sci')

exec('/home/birdy/Software/DOCK_v1-3/Module/Simulation/AOCS/QuaternionPD.sci')

//===== Load parameters for Xcos =====
exec('/home/birdy/Software/DOCK_v1-3/Module/Simulation/AOCS/load_para.sce') 

//===== Execute the Xcos =====
importXcosDiagram('/home/birdy/Software/DOCK_v1-3/Module/Simulation/AOCS/BIRDY_Dynamic_Attitude_Model.zcos')

typeof(scs_m) //The diagram data structure

scs_m.props.context;
xcos_simulate(scs_m, 4);

//===== Load the result of Xcos into Scilab workspace =====
BIRDY_ATT;

//===== Creating CIC file for VTS =====
exec('/home/birdy/Software/DOCK_v1-3/Module/Simulation/AOCS/XcosToVTSQuat.sci')
XcosToVTSQuat(BIRDY_ATT.values,51500,'QUATERNION','Birdy','/home/birdy/Software/DOCK_v1-3/Output/Dynamic_quat/','Birdy-quaternion-150825-070525.txt')

//===== Exit for Scilab =====
exit;
