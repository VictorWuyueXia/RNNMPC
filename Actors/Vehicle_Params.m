classdef Vehicle_Params
    % Vehicle parameters and limits settings,
    % as well as relevant functions

    properties
        ID = NaN % EgoCar ID

        Dynamics = NaN; 

        State = State(); % Current State

        Sensors = NaN; % Onboard sensors object
        
        Limits = Limits(); % Behavior Limits

    end

    methods
        function obj = Vehicle_Params(ID)
            obj.ID = ID;
            obj.Dynamics = Dyanmics();
            obj.State = State();
            obj.Sensors = Sensors(true); % With default configurations
            obj.Limits = Limits();
        end

        function obj = Set_iniStateFromScenario(obj,Scenario)
            obj.State=obj.State.ReadScenario(Scenario, obj.ID);
        end
    end
end