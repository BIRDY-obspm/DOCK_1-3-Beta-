// Attitude Controller with Quaternion feedback
// The parameters Kx, Ky, Kz, Kxd, Kyd, Kzd are defined in the CONTEXT
// The first element in the quaternion is the constant element.

function [Torque] = QuaternionPD(q, w)
    
    Kx  = 0.005;    
    Ky  = 0.005;
    Kz  = 0.006;
    
    Kxd = -0.3;
    Kyd = -0.3;
    Kzd = -0.3;
    
    Torque = [ 2*Kx*q(1)*q(2) + Kxd*w(1);
               2*Ky*q(1)*q(3) + Kyd*w(2);
               2*Kz*q(1)*q(4) + Kzd*w(3)];
    
    
endfunction
