// This function normalize the attitude quaternion
// This is done by dividing each term by the norm of the quaternion
// It is used in Attitude Kinematic block

function [q_N]=NormalizeQuat(q)
    
    q_N = q ./ sqrt(q(1)^2 + q(2)^2 + q(3)^2 + q(4)^2);
endfunction
