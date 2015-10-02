// This function is the angular rate controller.
// It use the Nonlinear Dynamic Inversion technique
// The inputs are: actual angular velocity, and desired angular velocity
// Ix,Iy, Iz are defined in simulation context
// Controller Gain are defined in ParameterLoader function
// Reference : Control System Application

function [NDI_torque]= NDI_rateControl(w, wd)
    
    
         Ux = -(Iy - Iz)*w(2)*w(3) - Cx*(w(1) - wd(1));
         Uy = -(Iz - Ix)*w(3)*w(1) - Cy*(w(2) - wd(2));
         Uz = -(Ix - Iy)*w(1)*w(2) - Cz*(w(3) - wd(3));
    
         NDI_torque = [Ux; Uy; Uz];
         
         
    
    
    
endfunction
