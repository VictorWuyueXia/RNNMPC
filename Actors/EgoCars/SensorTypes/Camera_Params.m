classdef Camera_Params
    % Camera params

    properties
        % Matlab Driving Scenario Designer App default params
        FOV=20; % deg

        FocalLength_X=1814.81; % corresponds to FOV=20deg
        FocalLength_Y=1814.81;

        Image_Width=640; % pixels
        Image_Height=480;
        OpticalCenter_X = 320;
        OpticalCenter_Y = 240;

        Range_Max=150; % meters

        Direction=0; % deg
    end

    methods
        function obj = Camera_Params(width, height, FOV)
            % Image Resolutions
            obj.Image_Width=width;
            obj.Image_Height=height;

            obj.OpticalCenter_X = width/2;
            obj.OpticalCenter_Y = height/2;

            % FOV
            obj.FOV=FOV;

            obj.FocalLength_X=obj.Image_Width/(2*tand(FOV/2));
            obj.FocalLength_Y=obj.Image_Height/(2*tand(FOV/2));
        end

        function obj = FieldOfView(obj, FOV)
            obj.FOV=FOV;

            obj.FocalLength_X=obj.Image_Width/(2*tand(FOV/2));
            obj.FocalLength_Y=obj.Image_Height/(2*tand(FOV/2));
        end
    end
end
