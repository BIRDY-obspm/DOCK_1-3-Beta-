=====Tutorial for Trajectory module=====
# Update developer: Hao-Chih, Lin (Jim, Lin) - 2015/10/29

# Abstract:
The "Trajectory" folder under DOCKS is an independent module.
Users can execute the trajectory solver for Earth-Mars mission directly without DOCKS.
For detail of trajectory solver, please see GSE-001 & GSE-002. 
(Notices: the whole program of "Trajectory" module follows LGPL license)

# Execution steps:
1. Go into "TrajectorySolver" folder, then you will see 4 python files, "host-trajectories" & "output-trajectories" folders.
2. Copy the "config(backup).py" file and rename it as "config.py". (you can modify parameters in config.py file)
3. Go into "host-trajectories" folder, copy "GL-01_sun_58122 (back up).xyzv" and rename it as "GL-01_sun_58122.xyzv".
4. Open a terminal, change the directory into "TrajectorySolver" folder location. ($ cd LOCATION_OF_TrajectorySolver)
5. Enter the following command to execute trajectory solver: $ python main.py 
6. Then you can find the result in "output-trajectories" folder.
 
