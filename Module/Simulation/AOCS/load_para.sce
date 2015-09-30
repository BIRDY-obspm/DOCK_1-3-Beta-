// Definition of some constants:
// Inertia of the satellite and momentum wheel

Ix=41.87e-3; 
Iy=41.87e-3;
Iz=6.667e-3;
Ixy=0.0;
Ixz=0.0;
Iyz=0.0;
I_Sat = [ Ix,  Ixy, Ixz  ;
          Ixy, Iy , Iyz  ;
          Ixz, Iyz, Iz   ];

Iwx=2E-6;   // Wheel on x-axis
Iwy=Iwx;
Iwz=Iwx;
I_wheels = [Iwx, 0  , 0   ;
            0  , Iwy, 0   ;
            0  , 0  , Iwz ];


//Thruster Geometric Configuration
// COM = center of mass
// GC  = geometric center

X_COM=0.00;   // X position of the COM with respect to GC
Y_COM=0.000;  // Y position of the COM with respect to GC
Z_COM=0.000;  // Z position of the COM with respect to GC

COM   = [X_COM; Y_COM; Z_COM];

// T1, T2, T3, and T4 are the Thruster Torque Orientation with respect to the 
// Body frame. We will normalize these vectors in order to get unit vector and
// Then compute the Unit Torque per thruster.

// Thruster 1
T1=[0;-0.259;0.966];                  // Thrust vector
T1= T1 ./ sqrt(T1' * T1);                 // Normalized Thrust Vector
OM1=[0.0305;-0.0419;-0.15275] - COM;    // Thruster Position With respect to COM
To1= cross(OM1, T1);                       // Torque vector

// Thruster 2
T2=[0;-0.259;0.966]; 
T2=T2 ./ sqrt(T2' * T2);
OM2=[-0.0305;-0.0419;-0.15275] - COM;
To2= cross(OM2, T2);

// Thruster 3
T3=[0;0.259;0.966];
T3=T3 ./ sqrt(T3' * T3);
OM3=[-0.0305;0.0419;-0.15275] - COM;
To3=cross(OM3, T3);

// Thruster 4
T4=[0;0.259;0.966];
T4=T4 ./sqrt(T4' * T4);
OM4=[0.0305;0.0419;-0.15275] - COM;
To4= cross(OM4, T4);

Ba=[To1,To2,To3,To4];

// Thruster Impulse
Thruster_Impulse_max=60e-6;
Thruster_Impulse_min=30e-6;
Thruster_on=50;               // This define the Duty cycle of the thruster in percentage
Thruster_period=1;                // This is the period of the thruster. It is the inverse
                                     // of the frequency.        

// Simulation Configuration: sim time, ...
T_sim=300;
Max_Step_Size=0.05;                // Maximum time step for simulation (used for integration)

// Controller Setup

    // 1. Rate Controller
         W_desired=[0;0.1;0];  //Desired Angular velocity
    
    // 2. Attitude Controller (angle controller)
         q_desired=[0.866;0;0;0.5];  // Desired attitude quaternion 
