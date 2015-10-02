// Least Norm
// Jim

function [T_tr_least_norm] = LN(T_tr)
    
F_impluse_min = 30e-6;
F_impluse_max = 60e-6;
xln = Ba'*inv(Ba*Ba')*T_tr;

for i=1:1:4
    if(xln(i) <= F_impluse_min)
        xln(i) = 0;
    end    
    if(xln(i) >= F_impluse_max)
        xln(i) = F_impluse_max;
    end
end
 

T_tr_least_norm = Ba*xln;
