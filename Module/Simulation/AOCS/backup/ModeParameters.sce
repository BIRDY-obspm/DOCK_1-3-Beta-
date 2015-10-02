// This function is for setting the initial contion, commands and also the different scenarios
// In AOCSmode.index: 1= detumbling(rate control), 2= spin, 3= attitrude, 4 = no control.
// If you want to set the 


// ***********************************Initial conditions ****************************************

T_sim = 6000;
w_init = [0; 0; 0];                 // initial angular velocity
q_init = [1; 0; 0; 0];              // initial quaternion
        
     
// ********************************Simulation modes***********************************************
// 1= detumbling(rate control), 2= spin, 3= attitrude, 4 = no control.

AOCSmode.number = 2;                           // This is the number of Modes
AOCSmode.index = cell();
AOCSmode.index(1).entries = [2;4];            // All mode contain the mode and the end mode 4. The number 4 is necessary it means the end of the mode.
AOCSmode.index(2).entries = [2;4];            //



AOCSmode.time = cell();
AOCSmode.time(1).entries = [-1; 100];         // each time need a start time and end time.
AOCSmode.time(2).entries = [200; 5000];



AOCSmode.Target = cell();
AOCSmode.Target(1).entries = [0; 0; 0.1];
AOCSmode.Target(2).entries = [0; 0; 0.5];
//AOCSmode.Target(3).entries = [0.866; 0; 0; 0.5];
//AOCSmode.Target(4).entries = [0; 0; 0.1];



// Do not change this part of the code
AOCSmodeCount = 1;
AOCSmode.CountVec = 1;
AOCSmode.timeVec = 0;
for AOCSmodeCount = 1:AOCSmode.number
    
    AOCSmode.timeVec(AOCSmode.CountVec)     = AOCSmode.time(AOCSmodeCount).entries(1,1);
    AOCSmode.timeVec(AOCSmode.CountVec + 1) = AOCSmode.time(AOCSmodeCount).entries(2,1);
    

    AOCSmode.CountVec = AOCSmode.CountVec + 2;
end


AOCSmodeCount = 1;
AOCSmode.CountVec = 1;
AOCSmode.indexVec = 0;
for AOCSmodeCount = 1:AOCSmode.number
    
    AOCSmode.indexVec(AOCSmode.CountVec)     = AOCSmode.index(AOCSmodeCount).entries(1,1);
    AOCSmode.indexVec(AOCSmode.CountVec + 1) = AOCSmode.index(AOCSmodeCount).entries(2,1);
    

    AOCSmode.CountVec = AOCSmode.CountVec + 2;
end
