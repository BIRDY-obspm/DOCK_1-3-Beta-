// This function is the angular rate controller.
// It use the Nonlinear Dynamic Inversion technique
// The inputs are: actual angular velocity, and desired angular velocity
// Ix,Iy, Iz are defined in simulation context
// Reference : Control System Application

function [NDI_torque]= NDI_rateControl(w, wd)
    
    // Controller Gain (can be change for performance)
    Cx = 10*Ix;
    Cy = 10*Iy;
    Cz = 10*Iz;
    
    Ux = -(Iy - Iz)*w(2)*w(3) - Cx*(w(1) - wd(1));
    Uy = -(Iz - Ix)*w(3)*w(1) - Cy*(w(2) - wd(2));
    Uz = -(Ix - Iy)*w(1)*w(2) - Cz*(w(3) - wd(3));
    
    NDI_torque = [Ux; Uy; Uz];
endfunction
