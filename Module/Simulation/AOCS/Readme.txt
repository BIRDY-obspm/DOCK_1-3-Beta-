=====Tutorial for AOCS model=====
# Original developer: Issouf - 2015/09/27
# Update person: Hao-Chih, Lin (Jim, Lin) - 2015/09/29

# Execution steps:
1. Open the "SatParameters.sce" file in "Inputs" folder, then modify the parameters to meet configurations of your satellite.
2. Open the "Seq_inputs_temp" in same folder, it is the sequence inputs definitions file for AOCS,
   related information is described in "Quaternion_sequence_inputs_template_v1-1" of same folder.
3. Now, open "Scilab", and chenge the directory into current main folder.
4. Open "Auto_exe.sce" in Scilab, and execute it.
5. Just wait a while (depending on your setting time of simulation), Scilab will automatically exit when finishing the simulation.
6. You can find the CIC format quaternion result file in "Outputs" folder.
