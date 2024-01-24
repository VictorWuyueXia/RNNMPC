classdef Limits
    % Vehicle Dynamics Parameters
    properties
        % limits
        speedMAX = 30; % m/s
        accMAX = 8; % m/s^2
        jerkMAX = 8;
        brakeMAX = 15; % m/s^2
        turnAngleMAX = deg2rad(30); % max turn angle in radian
        turnAngleRateMAX = deg2rad(30); % max turn angle change rate in radian

    end

    methods
        function obj = Limits()
            
        end

    end
end