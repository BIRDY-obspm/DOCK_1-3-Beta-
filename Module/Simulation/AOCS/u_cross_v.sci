// This function compute the cross product of two vector u and v

function [uv] = u_cross_v (u, v)
    [mu, nu] = size(u);
    [mv, nv] = size(v);
    if(mu*nv ~= 3 | nu*mv ~= 3)
        error("vectors dimensions are inconsistent. Dimension must be 3X1");
    end
    
    uv = [u(2)* v(3) - u(3) * v(2); u(3) * v(1) - u(1) * v(3); u(1) * v(2) - u(2) * v(1)];
endfunction
