function [MJD_date, MJD_sec, Q]=CIC_quat_gen( initial_quat, angular_vel, time_interval, start_MJD, end_MJD )
  % Abstract:
  %   Generate easy quaternion CIC format data by specific inputs
  %   Quaternion definition: q = q0 + q1*i + q2*j + q3*k
  % Author: 
  %   Hao-Chih, Lin   (Jim, Lin) 
  %   Internship student in Paris Observatory, graduated from NCKU, DAA in Taiwan
  % Final modified date:
  %   25/07/2015
  % E-mail:
  %   f44006076@gmail.com
  % ============================================================================
  % Input:
  %   'initial_quat'  is a 1x4 initial quaternion vector of satellite with respect to inertial frame
  %   'angular_vel'   is a 1x3 angular velocity vector on satellite frame
  %   'time_interval' is a double for setting the interval of iteration (unit; sec)
  %   'start_MJD'     is a 1x2 vector for starting time in MJD format
  %   'end_MJD'       is a 1x2 vector for ending time in MJD format
  % Output:
  %   'MJD_date'      is a nx1 (int) vector for the date part of MJD
  %   'MJD_sec'       is a nx1 (double) vetor for the sec paet of MJD
  %   'Q'             is a nx4 (double) matrix for quaternion data
  % Example:
  %   [MJD_date, MJD_sec, Q]=CIC_quat_gen([1 0 0 0],[1 2 0],0.1,[53006 86355.5],[53007 10]);
  % ============================================================================
  
  % Load parameters from input and normalize the initial quaternion
  q0 = initial_quat(1)/norm(initial_quat); 
  q1 = initial_quat(2)/norm(initial_quat);
  q2 = initial_quat(3)/norm(initial_quat);
  q3 = initial_quat(4)/norm(initial_quat);
  
  w = [angular_vel(1); angular_vel(2); angular_vel(3)];

  % Calculate the period of time
  if( end_MJD(2) > start_MJD(2) )
    time_duration = (end_MJD(1)-start_MJD(1))*86400.0 + (end_MJD(2)-start_MJD(2));
  else
    time_duration = ( (end_MJD(1)-1) - start_MJD(1) )*86400.0 + ( (end_MJD(2)+86400.0) - start_MJD(2) );
  endif
  
  % Initialize  
  date_ = start_MJD(1);
  sec_  = start_MJD(2);
  i = 0.0;
  count = 1;
  
  % Loop for generating data output
  while(i <= time_duration)
    
    M = [ -q1, -q2, -q3;
           q0,  q3, -q2;
          -q3,  q0,  q1;
           q2, -q1,  q0];
    
    q = [q0;q1;q2;q3];
    
    % predict the orientation by discrete quaternion differential equation
    qd = q + 0.5*time_interval*M*w;
    
    % normalize the quaternion
    qd = qd/norm(qd);
    
    Q( count, 1) = q0 = qd(1);
    Q( count, 2) = q1 = qd(2);
    Q( count, 3) = q2 = qd(3);
    Q( count, 4) = q3 = qd(4);
    
    % put the MJD data to output matrix
    if(sec_ < 86400.0)
      MJD_date(count,1) = int32(date_);
      MJD_sec(count,1)  = sec_;
      sec_ = sec_ + time_interval;
    else
      date_ = date_ + 1;
      sec_ = sec_ - 86400.0;
      MJD_date(count,1) = int32(date_);
      MJD_sec(count,1)  = sec_;
      sec_ = sec_ + time_interval;
    endif
    
    count = count + 1;
    i = i + time_interval;
  endwhile  

end
