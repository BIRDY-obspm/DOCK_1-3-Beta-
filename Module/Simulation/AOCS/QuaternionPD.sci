// Attitude Controller with Quaternion feedback
// The parameters Kx, Ky, Kz, Kxd, Kyd, Kzd are defined in the CONTEXT
// The first element in the quaternion is the constant element.

function [Torque] = QuaternionPD(q, q_E, w)
   
        Ux = 2*Kx*q_E(1)*q_E(2) + Kxd*w(1);
        Uy = 2*Ky*q_E(1)*q_E(3) + Kyd*w(2);
        Uz = 2*Kz*q_E(1)*q_E(4) + Kzd*w(3);
   
         Torque = [Ux; Uy; Uz];
endfunction

