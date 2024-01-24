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

            for i=1:length(Scenario.EgoCarId)
                % find this car from scenario
                if ID == Scenario.EgoCarId(i)

                    % Extract initial state from scenario
                    obj.Position=Scenario.ActorSpecifications(i).Position;
                    
                    Roll=Scenario.ActorSpecifications(i).Roll;
                    Pitch=Scenario.ActorSpecifications(i).Pitch;
                    Yaw=Scenario.ActorSpecifications(i).Yaw;
                    obj.Orientation=deg2rad([Roll Pitch Yaw]);
                    
                    break
                end
            end
        end

    end
end