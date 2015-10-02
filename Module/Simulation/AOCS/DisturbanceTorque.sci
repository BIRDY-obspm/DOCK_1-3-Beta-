// This function is to compute a simulated value of the disturbance torques.
// We consider the gravity gradient and solar pressure torque acting on the
// spacecraft. The values computed are in body frame.

function [Torque]=DisturbanceTorque(Position,SunVector)
    
    // Contribution of gravity
    GravityTorque = 3*gravity_constant.earth*cross(Position, I_Sat*Position)/((norm(Position))^5);

    
    // Contribution of sun pressure
    SatWettedArea = 0;                                   // represents the projected wetted area
    SatExposedRealArea = 0;                              // used to compute the center of pressure on the sat (denominator)
    WSatExposedRealArea = [0;0;0];                      // (weighted area)used to compute the center of pressure on the sat (numerator)
    
    Wetted_coef = SatVector.X_positive' * SunVector;
    if (Wetted_coef > 0) then
        
        SatWettedArea = SatWettedArea + SatArea.X_positive*Wetted_coef;
        SatExposedRealArea = SatExposedRealArea + SatArea.X_positive;
        WSatExposedRealArea = WSatExposedRealArea + SatAreaCenter.X_positive * SatArea.X_positive;
        
    end
    
    Wetted_coef = SatVector.X_negative' * SunVector;
    if (Wetted_coef > 0) then
        SatWettedArea = SatWettedArea + SatArea.X_negative*Wetted_coef;
        SatExposedRealArea = SatExposedRealArea + SatArea.X_negative;
        WSatExposedRealArea = WSatExposedRealArea + SatAreaCenter.X_negative * SatArea.X_negative;
    end
    
    Wetted_coef = SatVector.Y_positive' * SunVector;
    if (Wetted_coef > 0) then
        SatWettedArea = SatWettedArea + SatArea.Y_positive*Wetted_coef;
        SatExposedRealArea = SatExposedRealArea + SatArea.Y_positive;
        WSatExposedRealArea = WSatExposedRealArea + SatAreaCenter.Y_positive * SatArea.Y_positive;
    end
    
    Wetted_coef = SatVector.Y_negative' * SunVector;
    if (Wetted_coef > 0) then
        SatWettedArea = SatWettedArea + SatArea.Y_negative*Wetted_coef;
        SatExposedRealArea = SatExposedRealArea + SatArea.Y_negative;
        WSatExposedRealArea = WSatExposedRealArea + SatAreaCenter.Y_negative * SatArea.Y_negative;
    end
    
    Wetted_coef = SatVector.Z_positive' * SunVector;
    if (Wetted_coef > 0) then
        SatWettedArea = SatWettedArea + SatArea.Z_positive*Wetted_coef;
        SatExposedRealArea = SatExposedRealArea + SatArea.Z_positive;
        WSatExposedRealArea = WSatExposedRealArea + SatAreaCenter.Z_positive * SatArea.Z_positive;
    end
    
    Wetted_coef = SatVector.Z_negative' * SunVector;
    if (Wetted_coef >= 0) then
        SatWettedArea = SatWettedArea + SatArea.Z_negative*Wetted_coef;
        SatExposedRealArea = SatExposedRealArea + SatArea.Z_negative;
        WSatExposedRealArea = WSatExposedRealArea + SatAreaCenter.Z_negative * SatArea.Z_negative;
    end
    
    PressureCenter = WSatExposedRealArea/SatExposedRealArea;
    SolarForce     = SolarConstant * (1 + ReflectionCoef) * SatWettedArea * (-SunVector)/SpeedLight;
    
    SolarPressureTorque = cross((PressureCenter - COM), SolarForce);
    
    Torque =  GravityTorque ;
    
    
endfunction
