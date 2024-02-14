classdef costFuncWeights
    
    properties
        input=[1 1];
        progress=[1 1].*1e1;
        laneKeeping=[1];
        obsAvoid=[1e2];
        RL=[1];
        softConstraintPenalty=[1e-1];
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

