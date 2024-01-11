classdef Camera_Params
    % Camera params

    properties
        % Matlab Driving Scenario Designer App default params
        FOV=20; % deg

        FocalLength_X=1814.81; % corresponds to FOV=20deg
        FocalLength_Y=1814.81;

        Image_Width=640;
        Image_Height=480;

        Range_Max=150; % meters
    end

    methods
        function obj = Camera_Params(FOV)
            obj.FocalLength_X=obj.Image_Width/(2*tand(FOV/2));
            obj.FocalLength_Y=obj.Image_Height/(2*tand(FOV/2));
        end
    end
end
