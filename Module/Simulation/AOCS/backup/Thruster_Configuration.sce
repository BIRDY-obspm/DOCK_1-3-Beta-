//Thruster Geometric Configuration
// COM = center of mass
// GC  = geometric center

X_COM = 0.01;   // X position of the COM with respect to GC
Y_COM = 0.005;  // Y position of the COM with respect to GC
Z_COM = 0.008;  // Z position of the COM with respect to GC

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

