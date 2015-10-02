// This function convert Quaternion to Euler.

function [Euler]= myQuaternToEuler(q)
    
    
    
    
        
        M1 = 2*(q(3)*q(1) - q(2)*q(4));
        M2 = 1 - 2*(q(3)^2 + q(4)^2);
        M3 = 2*(q(2)*q(3) + q(4)*q(1));
        M4 = 2 * (q(2)* q(1) - q(3)* q(4));
        M5 = 1 - 2*(q(2)^2 + q(4)^2);
        
        
        Euler = [atan(M1, M2); asin(M3) ;atan(M4,M5)]*180/3.14;
        
        //Euler(1,1) = atan(M1, M2); 
        //Euler(1,2) = asin(M3); 
       // Euler(1,3) = atan(M4,M5);
    
  
    
    
endfunction


Countt = length(BIRDY_ATT.time);

for count = 1:Countt
    EulerAngle(:,count) = myQuaternToEuler(BIRDY_ATT.values(count,:));
end
