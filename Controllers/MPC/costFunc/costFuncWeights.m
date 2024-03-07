classdef costFuncWeights
    
    properties
        input=diag([1 10]).*1e0;
        progress=[1 0]'.*1e1;
        laneKeeping=[1 0]'.*1e2;
        obsAvoid=[1 0]';
        RL=[1 0]';
        softConstraintPenalty=[1e6 0]';
        % OutputVariables = [3 3];
        % ManipulatedVariablesRate = 0.1;

        weights
    end
    
    methods
        function obj = Weights()
        end
        
        function obj = vectorize(obj)
            obj.weights=[obj.input obj.progress obj.laneKeeping obj.obsAvoid obj.RL obj.softConstraintPenalty];
        end
    end
end

