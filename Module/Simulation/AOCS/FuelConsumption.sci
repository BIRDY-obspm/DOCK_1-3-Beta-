// This function is used to compute the fuel consumed during maneuvers

function [Total_fuel]= FuelConsumption(thruster_status, previous_Total_fuel)
    
    // previous_Total_fuel represent the fuel consume up to the previous time step
    
    Total_fuel = (thruster_status(1) + thruster_status(2) + thruster_status(3) + thruster_status(4)) * Thruster_fuel_per_pulse + previous_Total_fuel;
    //previous_Total_fuel = Total_fuel;

endfunction
