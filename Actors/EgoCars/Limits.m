classdef Limits
    % Vehicle Dynamics Parameters
    properties
        % limits
        speedMAX = 30; % m/s
        accMAX = 8; % m/s^2
        jerkMAX = 8;
        brakeMAX = 15; % m/s^2
        turnAngleMAX = 30; % max turn angle in radian
        turnAngleRateMAX = 30; % max turn angle change rate in radian
        
        limits = []; % Vectorized Array
    end

    methods
        function obj = Limits()
            
        end

        function obj = vectorize(obj)
            obj.limits=[obj.speedMAX obj.accMAX obj.jerkMAX obj.brakeMAX obj.turnAngleMAX obj.turnAngleRateMAX];
        end

    end
end