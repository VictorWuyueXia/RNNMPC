classdef State
    % Vehicle Dynamics Parameters
    properties
        
        Position=zeros(3,1); % Initial state 
        Velocity=zeros(3,1);
        Acceleration=zeros(3,1);
        Orientation=zeros(3,1);
        AngularVelocity=zeros(3,1);
        AngularAcceleration=zeros(3,1);
    end

    methods
        function obj = State()
            
        end

        function obj = ReadScenario(obj, Scenario, ID)
            % Extract initial state from scenario
            obj.Position=Scenario.ActorSpecifications(ID).Position;
            
            Roll=Scenario.ActorSpecifications(ID).Roll;
            Pitch=Scenario.ActorSpecifications(ID).Pitch;
            Yaw=Scenario.ActorSpecifications(ID).Yaw;
            obj.Orientation=[Roll Pitch Yaw];
        end

    end
end