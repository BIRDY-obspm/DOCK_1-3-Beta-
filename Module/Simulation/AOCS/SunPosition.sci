// Sun position
// This function compute the sun position. It receive the Julian Date as input.

function [SunPos]= SunPosition(JDate)
    
    MeanLong = 4.89495 + 0.017203*(JDate - 2451545);     // mean longitude of the sun
    MeanAnom = 6.24004 + 0.017202*(JDate - 2451545);     // Mean anomaly of the sun
    
    MeanLongCorrect = MeanLong + 0.033423*sin(MeanAnom) + 0.0003490658*sin(2*MeanAnom); // corrected mean longitude
    
    X_sun = cos(MeanLongCorrect);
    Y_sun = cos(23.439291*%pi/180)*sin(MeanLongCorrect);
    Z_sun = sin(23.439291*%pi/180)*sin(MeanLongCorrect);
    
    SunPos = [X_sun; Y_sun; Z_sun];
    
endfunction
