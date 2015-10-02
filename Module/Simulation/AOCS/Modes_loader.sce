// This function is for setting the initial contion, commands and also the different scenarios
// In AOCSmode.index: 1= detumbling(rate control), 2= spin, 3= attitrude, 4 = no control.
// If you want to set the 
// ********************************Simulation modes***********************************************
// Load definition of modes from Seq_inputs_temp file
Seq_data = read_csv(pwd() + '/Inputs/Seq_inputs_temp', " ");

// Initialize the 'AOCSmode'
AOCSmode.number = size(Seq_data,'r');    // This is the number of Modes
AOCSmode.index = cell();
AOCSmode.time = cell();
AOCSmode.Target = cell();

// Convert the MJD date into simulation timing
for i=1:1:size(Seq_data,'r')
	Start_MJD(i) = strtod(Seq_data(i,1)) + strtod(Seq_data(i,2)) / 86400.0;
	End_MJD(i) = strtod(Seq_data(i,3)) + strtod(Seq_data(i,4)) / 86400.0;
end		

End_MJD = ( End_MJD - Start_MJD(1) )*86400.0 - 1.0;
Start_MJD = ( Start_MJD - Start_MJD(1) )*86400.0 - 1.0;

// Initial conditions 
T_sim = End_MJD(size(End_MJD, 'r'));
w_init = strtod(  [Seq_data(1,11); Seq_data(1,12); Seq_data(1,13)]  );                 // initial angular velocity
q_init = strtod(  [Seq_data(1,7); Seq_data(1,8); Seq_data(1,9); Seq_data(1,10)]  );   // initial quaternion


// Set up the 'AOCSmode' (1= DETUMB, 2= spin, 3= attitrude, 4 = no control).
if(Seq_data(1,5) == 'DETUMB')
	AOCSmode.index(1).entries = [1;4];
	AOCSmode.time(1).entries = [-1; End_MJD(1)];
	AOCSmode.Target(1).entries = [0,0,0];
elseif(Seq_data(1,5) == 'SPIN')
	AOCSmode.index(1).entries = [2;4];
	AOCSmode.time(1).entries = [-1; End_MJD(1)];
	AOCSmode.Target(1).entries = strtod(  [Seq_data(1,18); Seq_data(1,19); Seq_data(1,20)]  );
elseif(Seq_data(1,5) == 'POINT')
	AOCSmode.index(1).entries = [3;4];
	AOCSmode.time(1).entries = [-1; End_MJD(1)];
	AOCSmode.Target(1).entries = strtod(  [Seq_data(1,14); Seq_data(1,15); Seq_data(1,16); Seq_data(1,17)]  );
else(Seq_data(1,5) == 'SAFE')
	AOCSmode.index(1).entries = [4;4];
	AOCSmode.time(1).entries = [-1; End_MJD(1)];
end

if (size(Seq_data,'r') > 1 )
	for i=2:1:size(Seq_data,'r')
		if(Seq_data(i,5) == 'DETUMB')
			AOCSmode.index(i).entries = [1;4];
			AOCSmode.time(i).entries = [Start_MJD(i); End_MJD(i)];
			AOCSmode.Target(i).entries = [0,0,0];
		elseif(Seq_data(i,5) == 'SPIN')
			AOCSmode.index(i).entries = [2;4];
			AOCSmode.time(i).entries = [Start_MJD(i); End_MJD(i)];
			AOCSmode.Target(i).entries = strtod(  [Seq_data(i,18); Seq_data(i,19); Seq_data(i,20)]  );
		elseif(Seq_data(i,5) == 'POINT')
			AOCSmode.index(i).entries = [3;4];
			AOCSmode.time(i).entries = [Start_MJD(i); End_MJD(i)];
			AOCSmode.Target(i).entries = strtod(  [Seq_data(i,14); Seq_data(i,15); Seq_data(i,16); Seq_data(i,17)]  );
		else(Seq_data(i,5) == 'SAFE')
			AOCSmode.index(i).entries = [4;4];
			AOCSmode.time(i).entries = [Start_MJD(i); End_MJD(i)];
		end
	end
end


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

