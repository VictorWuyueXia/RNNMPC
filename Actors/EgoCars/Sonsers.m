classdef Sonsers
    % Onboard sensors

    properties
        INS=NaN
        cameras=NaN
        radars=NaN
        ultrasounds=NaN
        Lidars=NaN
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
            
            % front wide camera with 90deg FOV and 60m range
            Camera_EgoCar0_FrontWide=Camera_Params(90);
            Camera_EgoCar0_FrontWide.Range_Max=60;
            
            % front long range radar with 20deg FOV and 150m range (default)
            Radar_EgoCar0_FrontLongRange=Radar_Params();
            
            % front long range radar with 90deg FOV and 30m range
            Radar_EgoCar0_RearWide=Radar_Params();
            Radar_EgoCar0_RearWide.FOV=90;
            Radar_EgoCar0_RearWide.range=30;
            
            % 6 ultrasound with 90deg FOV and 5.5m range
            Ultrasound_EgoCar0_Front=Ultrasound_Params();
            Ultrasound_EgoCar0_Rear=Ultrasound_Params();
            Ultrasound_EgoCar0_FrontLeft=Ultrasound_Params();
            Ultrasound_EgoCar0_FrontRight=Ultrasound_Params();
            Ultrasound_EgoCar0_RearLeft=Ultrasound_Params();
            Ultrasound_EgoCar0_RearRight=Ultrasound_Params();
            
            obj.INS=INS_EgoCar0;
            obj.cameras=Camera_EgoCar0_FrontWide;
            obj.radars=[Radar_EgoCar0_FrontLongRange Radar_EgoCar0_RearWide];
            obj.ultrasounds=[Ultrasound_EgoCar0_Front Ultrasound_EgoCar0_Rear ...
                Ultrasound_EgoCar0_FrontLeft Ultrasound_EgoCar0_FrontRight ...
                Ultrasound_EgoCar0_RearLeft Ultrasound_EgoCar0_RearRight];
        end
    end
end