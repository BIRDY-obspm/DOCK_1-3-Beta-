// This function compute the quaternion Error


function [q_error]=QuaternionError(qs, qt)
    

    q_error = [qt(1), -qt(2), -qt(3), -qt(4);
               qt(2),  qt(1),  qt(4), -qt(3);
               qt(3), -qt(4),  qt(1),  qt(2);
               qt(4),  qt(3), -qt(2),  qt(1)] * [qs(1); -qs(2); -qs(3); -qs(4)];
               
endfunction
