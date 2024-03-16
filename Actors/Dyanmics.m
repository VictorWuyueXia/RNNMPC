classdef Dyanmics
    % Vehicle Dynamics Parameters
    properties
        % The following are default settings from Simulink 3DOF - Force Input block
        m = 2000;      % Total mass of vehicle                          (kg)
        Iz = 4000;     % Yaw moment of inertia of vehicle               (m*N*s^2)
        lf = 1.5;      % Longitudinal distance from c.g. to front tires (m)
        lr = 1.5;      % Longitudinal distance from c.g. to rear tires  (m)
        Cf = 12e3;    % Cornering stiffness of front tires             (N/rad)
        Cr = 11e3;    % Cornering stiffness of rear tires              (N/rad)
        % tauLong = 0.5;     % time constant for longitudinal dynamics        (1/s/(tau*s+1))
        % tauSteer = 0.2;
    end

    methods
        function obj = Dyanmics()
            
        end

    end
end