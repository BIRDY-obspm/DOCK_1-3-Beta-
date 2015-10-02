// The purpose of this function is to load the necessary parameters needed to
// run the Xcos model


    
//***********************************Satellite Inertia *************************************************
// Inertia of the satellite and momentum wheel

Ix = 0.0422;//41.87e-3; 
Iy = 0.0425;//41.87e-3;
Iz = 0.0072;//6.667e-3;
Ixy = -0.0002;
Ixz =  -0.0003;
Iyz = -0.0002;
I_Sat = [ Ix,  Ixy, Ixz  ;
          Ixy, Iy , Iyz  ;
          Ixz, Iyz, Iz   ];

Iwx = 2e-6;   // Wheel on x-axis
Iwy = Iwx;
Iwz = Iwx;
I_wheels = [Iwx, 0  , 0   ;
            0  , Iwy, 0   ;
            0  , 0  , Iwz ];

Sat_mass = 4;

// *********************************************** Thrusters *******************************************
//Thruster Geometric Configuration
// COM = center of mass
// GC  = geometric center

X_COM = 0.01;   // X position of the COM with respect to GC
Y_COM = 0.01;  // Y position of the COM with respect to GC
Z_COM = 0.01;  // Z position of the COM with respect to GC

COM   = [X_COM; Y_COM; Z_COM];

// T1, T2, T3, and T4 are the Thruster Torque Orientation with respect to the 
// Body frame. We will normalize these vectors in order to get unit vector and
// Then compute the Unit Torque per thruster.

// Thruster 1
T1  = [ 0; -0.259; 0.966];                  // Thrust vector
T1  = T1 ./ sqrt(T1' * T1);                 // Normalized Thrust Vector
OM1 = [0.0305; -0.0419; -0.15275] - COM;    // Thruster Position With respect to COM
To1 = cross(OM1, T1);                       // Torque vector

// Thruster 2
T2  = [0;-0.259;0.966]; 
T2  = T2 ./ sqrt(T2' * T2);
OM2 = [-0.0305;-0.0419;-0.15275] - COM;
To2 = cross(OM2, T2);

// Thruster 3
T3  = [0;0.259;0.966];
T3  = T3 ./ sqrt(T3' * T3);
OM3 = [-0.0305;0.0419;-0.15275] - COM;
To3 = cross(OM3, T3);

// Thruster 4
T4  = [0;0.259;0.966];
T4  = T4 ./sqrt(T4' * T4);
OM4 = [0.0305;0.0419;-0.15275] - COM;
To4 = cross(OM4, T4);

Ba  = [To1, To2, To3, To4];          
Ta  = [T1,  T2,  T3,  T4 ];             // This quantity is used in the Delta V estimation block
LeastNorm_Factor = Ba' / (Ba * Ba');    // This Quantity is used in the LeastNormTorque function.

// Thruster Impulse
Thruster_Impulse_max = 60e-6;
Thruster_Impulse_min = 30e-6;
Thruster_fuel_margin = 1.2;                                   // Margin of 20%
Total_fuel = [0,0,0,0,0];
Thruster_fuel_per_pulse = 8.49e-6 * Thruster_fuel_margin;    // Fuel consumption per pulse. (used in fuel consemption function)
Thruster_on      = 50;                                       // This define the Duty cycle of the thruster in percentage
Thruster_period  = 1;                                        // This is the period of the thruster. It is the inverse
                                                             // of the frequency.        

// Simulation Configuration: sim time, ...
T_sim = 400;
Max_Step_Size = 0.05;                // Maximum time step for simulation (used for integration)




// **********************************DISTURBANCE**************************************************

// Gravity gradient
gravity_constant.earth = 398600.4418;     // Earth's gravitational constant (GM) km^3/s^2
gravity_constant.mars  = 42828;           // Mars gravitational constant (GM)
satellite_position = [800 ; 0; 0];     // Satellite position is assume constant for gravity gradient torque. km


// Sun Pressure torque

SunDir        = [ 0.433;  0.75; 0.5];          // Sun direction unit vector in inertial frame
SolarConstant = 1371;               // W/m^2
SpeedLight        = 3e8;                // m/s (exact value = 299792458)
ReflectionCoef    = 0.6;                // reflection coefficient (From book: space mission analysis and design)

SatArea.X_positive = 0.034;                  // area in the positive x direction (will be used to compute solar pressure force)
SatArea.X_negative = 0.034;
SatArea.Y_positive = 0.034;
SatArea.Y_negative = 0.034;
SatArea.Z_positive = 0.01;
SatArea.Z_negative = 0.01;

SatVector.X_positive = [1; 0;  0];
SatVector.X_negative = [-1; 0; 0];
SatVector.Y_positive = [0; 1;  0];
SatVector.Y_negative = [0; -1; 0];
SatVector.Z_positive = [0; 0;  1];
SatVector.Z_negative = [0; 0; -1];

SatAreaCenter.X_positive = [0.05; 0;  0];
SatAreaCenter.X_negative = [-0.05; 0; 0];
SatAreaCenter.Y_positive = [0; 0.05;  0];
SatAreaCenter.Y_negative = [0; -0.05; 0];
SatAreaCenter.Z_positive = [0; 0;  0.17];
SatAreaCenter.Z_negative = [0; 0; -0.17];





//*********************************************** SENSORS NOISE **********************************************


SunSensor.mean = [0; 0; 0];
SunSensor.deviation = [0.01; 0.01; 0.01];
SunSensor.period = 0.1;                               // period = 1/frequency


RateSensor.mean = [0; 0; 0];
RateSensor.deviation = [0.01; 0.01; 0.01];
RateSensor.period = 0.1;                             //period = 1/frequency

// ********************************** Contrllers Gains *******************************************

// Rate Controller

    Cx = 0.4187;//2.5*Ix;
    Cy = 0.4187;//2.5*Iy;
    Cz = 0.0667;//2.5*Iz;
    
    Cx_Wheel = 4*Ix;
    Cy_Wheel = 10*Iy;
    Cz_Wheel = 5*Iz;


// Attitude Controller

    Kx  = 0.005;   Kx_w = 0.00005;
    Ky  = 0.005;   Ky_w = 0.00005;
    Kz  = 0.006;   Kz_w = 0.00005;
    
    Kxd = -0.3;  Kxd_w = -0.004;
    Kyd = -0.3;  Kyd_w = -0.004;
    Kzd = -0.3;  Kzd_w = -0.004;
    
    

