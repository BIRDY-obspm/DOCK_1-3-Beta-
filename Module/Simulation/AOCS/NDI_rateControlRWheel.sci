// This function is the angular rate controller.
// It use the Nonlinear Dynamic Inversion technique
// The inputs are: actual angular velocity, and desired angular velocity
// Ix,Iy, Iz are defined in simulation context
// Controller Gain are defined in ParameterLoader function
// Reference : Control System Application

function [WheelSpeed]= NDI_rateControlRWheel(w, wd)
    
    
         
         Ux = (Iy - Iz)*w(2)*w(3) + Cx_Wheel*(w(1) - wd(1));
         Uy = (Iz - Ix)*w(3)*w(1) + Cy_Wheel*(w(2) - wd(2));
         Uz = (Ix - Iy)*w(1)*w(2) + Cz_Wheel*(w(3) -  wd(3));
         
               
         
         WheelSpeed = [Ux; Uy;  Uz]/Iwx;
    
    
    
endfunction
