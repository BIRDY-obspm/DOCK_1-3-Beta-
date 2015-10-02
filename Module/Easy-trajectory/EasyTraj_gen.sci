function [] = EasyTraj_gen(sma, ecc, inc, pom, gom, anm, type_oe, start_time, end_time, step_size, Sat_name, Body_name, File_path)
    
    // Check the definition of parameters is correct
    if start_time(1) < 10000 | start_time(2) < 0.0 | end_time(1) < 10000 | end_time(2) < 0.0 then
        printf("MJD date should be greater than 10000 and the sec has to be greater than 0!\n");
        return 0;
    end
    
    if start_time(1) > end_time(1) then
        printf("The end time is late than start time!\n");
        return 0;
    elseif start_time(1) == end_time(1) then
        if start_time(2) >= end_time(2) then
            printf("The end time is late than start time!\n");
            return 0;
        end
    end
    
    
    t0 = start_time(1) + start_time(2)/86400.0;
    tf = end_time(1) + end_time(2)/86400.0;
    count = 1
    t(count) = t0;
    
    Date(1,:) = start_time;
    step_sum = start_time(2);
    while ( t(count) + step_size/86400.0 ) < tf
        // Time data for CL_ex_propagate function
        t(count+1) = t(count) + step_size/86400.0;
        
        // Time data for EasyTraj2CIC function
        if (step_sum + step_size)  < 86400.0
            step_sum = step_sum + step_size;
            Date(count+1,:) = [Date(count,1), step_sum];
        else
            step_sum = step_sum + step_size - 86400.0;
            Date(count+1,:) = [Date(count,1)+1, step_sum];
        end
        count = count + 1;
    end
    t(count+1) = tf;
    Date(count+1,:) = end_time;
    t = t'; 
    Date = Date';
    
    // Propagate
    if type_oe == "Keplerian" then
        moe = [sma; ecc; inc; pom; gom; anm]; 
        result = CL_ex_propagate("lydlp", "kep", t0, moe, t, "o"); 
        [pos_eci, vel_eci] = CL_oe_kep2car(result); 
        pos_eci = pos_eci';
        vel_eci = vel_eci';
    else
        ecc_x = ecc*cos(pom);
        ecc_y = ecc*sin(pom);
        pso   = pom + anm;
        moe = [sma; ecc_x; ecc_y; inc; gom; pso];
        
        result = CL_ex_propagate("central", "cir", t0, moe, t, "o"); 
        [pos_eci, vel_eci] = CL_oe_cir2car(result); 
        pos_eci = pos_eci';
        vel_eci = vel_eci';
    end
    
    // Call the EasyTraj2CIC function
    exec('EasyTraj2CIC.sci')
    
    // Generate CIC position file output
    Date = Date';
    EasyTraj2CIC(Date, pos_eci/1000.0, vel_eci/1000.0, Sat_name, Body_name, File_path);

    printf("Success!\n");
endfunction
