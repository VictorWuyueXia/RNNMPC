classdef Limits
    % Vehicle Dynamics Parameters
    properties
        % limits
        speedMAX = 10; % m/s
        reverseMAX = 0; % m/s
        accMAX = 8; % m/s^2
        jerkMAX = 16;
        brakeMAX = 16; % m/s^2
        turnAngleMAX = 15; % max turn angle in radian
        turnAngleRateMAX = 30; % max turn angle change rate in radian
        
        limits = []; % Vectorized Arrays
    end

    methods
        function obj = Limits()
            
        end

        function obj = vectorize(obj)
            obj.limits=[obj.speedMAX obj.reverseMax obj.accMAX obj.jerkMAX obj.brakeMAX obj.turnAngleMAX obj.turnAngleRateMAX];
        end

    end
end