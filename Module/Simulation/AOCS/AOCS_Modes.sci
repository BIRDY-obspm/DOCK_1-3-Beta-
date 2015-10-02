// This unction decide whcih mode to trigger based on the input time.

function [q_target, w_target, AOCS_mode]=AOCS_Modes(time)
    
    q_target = [1; 0; 0; 0]; // initialization; it does not affect the reste of your setting in the ModesParameters functions.
    w_target = [0; 0; 0];   
    
    time_index = AOCSmode.number;
    
    while (time < AOCSmode.timeVec(time_index))
        
          time_index = time_index - 1;
          
    end 
    
    
    select AOCSmode.indexVec(time_index)
        
        case 1 then
            w_target = AOCSmode.Target(time_index);
            w_target = cell2mat(w_target);
        
        case 2 then
            w_target = AOCSmode.Target(time_index);
            w_target = cell2mat(w_target);
        
        case 3 then
            q_target = AOCSmode.Target(time_index);
            q_target = cell2mat(q_target);
        
    end
    
     AOCS_mode  = AOCSmode.indexVec(time_index);
    
endfunction
