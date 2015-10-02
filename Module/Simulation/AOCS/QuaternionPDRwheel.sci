// Attitude Controller with Quaternion feedback
// The parameters Kx, Ky, Kz, Kxd, Kyd, Kzd are defined in the CONTEXT
// The first element in the quaternion is the constant element.

function [Torque] = QuaternionPDRwheel(q, q_E, w)
    
    global SwitchToWheel
    global q_desired
    if (abs( q - q_desired) <= q_tolerance)   then
        
        if (SwitchToWheel == 1) then
            q_desired = q;
            SwitchToWheel = 0;
        end 
        
        Torque = -[ 2*Kx_w*q_E(1)*q_E(2) + Kxd_w*w(1);
                    2*Ky_w*q_E(1)*q_E(3) + Kyd_w*w(2);
                    2*Kz_w*q_E(1)*q_E(4) + Kzd_w*w(3)]/Iwx;
    else 
        
        SwitchToWheel = 1;
        Torque = [0; 0; 0];
               
    end
    
        
    
endfunction
