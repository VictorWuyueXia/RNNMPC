classdef Vehicle_Params
    % Vehicle parameters and limits settings,
    % as well as relevant functions

    properties
        ID = 0 % EgoCar ID

        % The following are default settings from Simulink 3DOF - Force Input block
        m = 2000;      % Total mass of vehicle                          (kg)
        Iz = 4000;     % Yaw moment of inertia of vehicle               (m*N*s^2)
        lf = 1.5;      % Longitudinal distance from c.g. to front tires (m)
        lr = 1.5;      % Longitudinal distance from c.g. to rear tires  (m)
        Cf = 12e3;    % Cornering stiffness of front tires             (N/rad)
        Cr = 11e3;    % Cornering stiffness of rear tires              (N/rad)
        tauLong = 0.5;     % time constant for longitudinal dynamics        (1/s/(tau*s+1))
        tauSteer = 0.2;
        
        % limits
        speedMAX = 30; % m/s
        accMAX = 8; % m/s^2
        jerkMAX = 8;
        brakeMAX = 15; % m/s^2
        turnAngleMAX = deg2rad(30); % max turn angle in radian
        turnAngleRateMAX = deg2rad(30); % max turn angle change rate in radian

        Sensors = NaN; % Onboard sensors object

        state=zeros(6,1); % Current state [x,y,vx,vy,yaw,yawRate]'
    end

    methods
        function obj = Vehicle_Params(ID)
            obj.ID = ID;
        end

        function obj = Set_iniStateFromScenario(obj, data)
            % Extract initial state from scenario
            for i=1:length(data.EgoCarId)
                % find this car's ID
                if obj.ID == data.EgoCarId(i)
                    % Extract initial state from scenario
                    position0=data.ActorSpecifications.Position(i,1:2);
                    velocity0=[0 0];
                    yaw0=data.ActorSpecifications.Yaw(i);
                    yawRate0=0;

                    % assign state
                    obj.state=[position0 velocity0 yaw0 yawRate0];

                    break
                end
            end
        end
    end
end