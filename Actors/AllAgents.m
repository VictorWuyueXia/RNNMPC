classdef AllAgents
    % Collections of all agents
    % Only actually useful when there are multiple agents (egocars)

    properties
        NumAgents=0
        Agents=NaN
    end

    methods
        function obj = AllAgents(agents)
            obj.NumAgents=length(agents);
            obj.Agents=agents;
        end

    end
end