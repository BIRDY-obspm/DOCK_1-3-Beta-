function [MJD_date_output, MJD_sec_output, Q_output]=CIC_quat_gen_seq_inputs( file_name )
  % Abstract:
  %   Generate easy quaternion CIC format data by sequence inputs.
  %   This function can only work correctly with "CIC_quat_gen.m" which should be put the same folder as this file. 
  %   Quaternion definition: q = q0 + q1*i + q2*j + q3*k
  % Author: 
  %   Hao-Chih, Lin   (Jim, Lin) 
  %   Internship student in Paris Observatory, graduated from NCKU, DAA in Taiwan
  % Final modified date:
  %   27/07/2015
  % E-mail:
  %   f44006076@gmail.com
  % ============================================================================
  % Input:
  %   'file name' is a string of spcial sequence inputs file's name
  %   (There is an example "sequence inputs" file in current folder called "ADCS_sequence_inputs_example_v1")
  % Output:
  %   'MJD_date_output'      is a nx1 (int) vector for the date part of MJD
  %   'MJD_sec_output'       is a nx1 (double) vetor for the sec paet of MJD
  %   'Q_output'             is a nx4 (double) matrix for quaternion data
  % Example:
  %   [MJD_date, MJD_sec, Q]=CIC_quat_gen_seq_inputs('ADCS_sequence_inputs_example_v1');
  % ============================================================================
	fid = fopen(file_name, 'r');
	Data = textscan (fid, '%s', 'delimiter', '\n', 'whitespace', '');
	Data = cell2mat(Data);

	s = size(Data);
	ang_output = [];	
	Q_output = [];
	MJD_date_output = [];
	MJD_sec_output = [];

	for i=1:s(1)
		time_interval = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(6) )  );

		start_MJD_date = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(1) )  );
		start_MJD_sec = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(2) )  );
		start_MJD_sec = start_MJD_sec + time_interval;
		start_MJD = [start_MJD_date, start_MJD_sec];

		end_MJD_date = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(3) )  );
		end_MJD_sec = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(4) )  );
		end_MJD = [end_MJD_date, end_MJD_sec];

		Mode = cell2mat( strsplit( cell2mat(Data(i)), " ")(5) );

		

		if ( cell2mat( strsplit( cell2mat(Data(i)), " ")(7) ) == 'c' )
			if ( i == 1 )
				initial_quat = [1 0 0 0];
			else
				initial_quat = Q_output(end,:);
			endif
		else
			initial_quat_w = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(7) )  );
			initial_quat_x = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(8) )  );
			initial_quat_y = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(9) )  );
			initial_quat_z = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(10) )  );
			initial_quat = [initial_quat_w, initial_quat_x, initial_quat_y, initial_quat_z];
		endif
		
		if ( cell2mat( strsplit( cell2mat(Data(i)), " ")(11) ) == 'c' )
			if ( i == 1 )
				initial_ang = [0 0 0];
			else
				initial_ang = ang_output(end,:);
			endif

		else
			initial_ang_x = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(11) )  );
			initial_ang_y = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(12) )  );
			initial_ang_z = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(13) )  );
			initial_ang = [initial_ang_x, initial_ang_y, initial_ang_z];
		endif

		desired_quat_w = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(14) )  );
		desired_quat_x = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(15) )  );
		desired_quat_y = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(16) )  );
		desired_quat_z = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(17) )  );
		desired_quat = [desired_quat_w, desired_quat_x, desired_quat_y, desired_quat_z];

		desired_ang_x = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(18) )  );
		desired_ang_y = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(19) )  );
		desired_ang_z = str2double(  cell2mat( strsplit( cell2mat(Data(i)), " ")(20) )  );
		desired_ang = [desired_ang_x, desired_ang_y, desired_ang_z];

		if ( Mode == 'SPIN' )
			[MJD_date, MJD_sec, Q]=CIC_quat_gen( initial_quat, desired_ang, time_interval, start_MJD, end_MJD );
			Q_output = [Q_output;Q];
			MJD_date_output = [MJD_date_output;MJD_date];
			MJD_sec_output = [MJD_sec_output;MJD_sec];
			ang_output = desired_ang;
		endif
	end
end
