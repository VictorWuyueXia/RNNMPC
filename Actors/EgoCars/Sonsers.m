classdef Sonsers
    % Onboard sensors

    properties
        INS=NaN
        cameras=NaN
        radars=NaN
        ultrasounds=NaN
        lidars=NaN
    end

    methods
        function obj = Sonsers(default)
            if default
                obj=obj.defaultConfig();
            end
        end

        function obj=defaultConfig(obj)
            % On-board INS
            INS_EgoCar0=INS_Params;
            
            % Front camera with 60deg FOV and 100m range
            Camera_EgoCar0_FrontWide=Camera_Params(60);
            Camera_EgoCar0_FrontWide.Range_Max=100;

            % Lidar with 120m range
            Lidar_EgoCar0_Center=Lidar_Params;
            Lidar_EgoCar0_Center.Range_Max=120;
            
            % % Front radar with 90deg FOV and 50m range
            % Radar_EgoCar0_Front=Radar_Params();
            % Radar_EgoCar0_Front.FOV=90;
            % Radar_EgoCar0_Front.range=50;
            % Radar_EgoCar0_Front.direction=0;
            % 
            % % Rear radar with 90deg FOV and 50m range
            % Radar_EgoCar0_Rear=Radar_Params();
            % Radar_EgoCar0_Rear.FOV=90;
            % Radar_EgoCar0_Rear.range=50;
            % Radar_EgoCar0_Rear.direction=180;
            % 
            % % Left radar with 90deg FOV and 50m range
            % Radar_EgoCar0_Left=Radar_Params();
            % Radar_EgoCar0_Left.FOV=90;
            % Radar_EgoCar0_Left.range=50;
            % Radar_EgoCar0_Left.direction=90;
            % 
            % % Right radar with 90deg FOV and 50m range
            % Radar_EgoCar0_Right=Radar_Params();
            % Radar_EgoCar0_Right.FOV=90;
            % Radar_EgoCar0_Right.range=50;
            % Radar_EgoCar0_Right.direction=-90;
            
            obj.INS=INS_EgoCar0;
            obj.cameras=Camera_EgoCar0_FrontWide;
            obj.lidars=Lidar_EgoCar0_Center;
            % obj.radars=[Radar_EgoCar0_Front Radar_EgoCar0_Rear ...
            %     Radar_EgoCar0_Left Radar_EgoCar0_Right];
            
        end
    end
end