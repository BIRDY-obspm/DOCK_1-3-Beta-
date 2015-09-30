// This function compute the matrix [Ω'] for quaternion kinematics
// Its input is the satellite angular velocity given in satellite
// body-frame.
// Reference: Strapdown Attitude Algorithms using Quaternion Transition Matrix And Random Inputs, Mohamed S.Ahmed (Attitude control)

function [Omega] = OmegaPrime(w)
    
    Omega = [ 0    ,  -w(1)  , -w(2) ,  -w(3);
              w(1) ,   0     ,  w(3) ,  -w(2);
              w(2) ,  -w(3) ,  0    ,  w(1);
              w(3) ,   w(2) , -w(1) ,  0     ];
             
endfunction
