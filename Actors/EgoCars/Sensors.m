classdef Sensors
    % Onboard sensors

    properties
        INS=NaN
        cameras=NaN
        radars=NaN
        ultrasounds=NaN
        lidars=NaN
    end

    methods
        function obj = Sensors(default)
            if default
                obj=obj.defaultConfig();
            end
        end

        function obj=defaultConfig(obj)
            % On-board INS
            INS_EgoCar0=INS_Params;
            
            % Front camera with 90deg FOV and 50m range, 1080p
            Camera_EgoCar0_Front=Camera_Params(1920, 1080, 90);
            Camera_EgoCar0_Front.Direction=0; % deg
            Camera_EgoCar0_Front.Range_Max=50; % meters

            % Back camera with 90deg FOV and 50m range, 1080p
            Camera_EgoCar0_Back=Camera_Params(1920, 1080, 90);
            Camera_EgoCar0_Back.Direction=180; % deg
            Camera_EgoCar0_Back.Range_Max=50; % meters

            % Left camera with 90deg FOV and 50m range, 1080p
            Camera_EgoCar0_Left=Camera_Params(1920, 1080, 90);
            Camera_EgoCar0_Left.Direction=90; % deg
            Camera_EgoCar0_Left.Range_Max=50; % meters

            % Right camera with 90deg FOV and 50m range, 1080p
            Camera_EgoCar0_Right=Camera_Params(1920, 1080, 90);
            Camera_EgoCar0_Right.Direction=-90; % deg
            Camera_EgoCar0_Right.Range_Max=50; % meters

            % Front telescope camera with 30deg FOV and 150m range, 1080p
            Camera_EgoCar0_TeleFront=Camera_Params(1920, 1080, 30);
            Camera_EgoCar0_TeleFront.Direction=0; % deg

            % Front telescope camera with 30deg FOV and 150m range, 1080p
            Camera_EgoCar0_TeleBack=Camera_Params(1920, 1080, 30);
            Camera_EgoCar0_TeleBack.Direction=-180; % deg

            % % Radar with 90deg FOV and 50m range
            % Radar_EgoCar0=Radar_Params();
            % Radar_EgoCar0.FOV=90;
            % Radar_EgoCar0.range=50;
            % Radar_EgoCar0.direction=0;
            
            % % Lidar with 120m range
            % Lidar_EgoCar0_Center=Lidar_Params;
            % Lidar_EgoCar0_Center.Range_Max=120;
            
            obj.INS=INS_EgoCar0;
            obj.cameras=[Camera_EgoCar0_Front Camera_EgoCar0_Back ...
                Camera_EgoCar0_Left Camera_EgoCar0_Right ...
                Camera_EgoCar0_TeleFront Camera_EgoCar0_TeleBack];
            % obj.lidars=Lidar_EgoCar0_Center;
            % obj.radars=[Radar_EgoCar0];
            
        end
    end
end