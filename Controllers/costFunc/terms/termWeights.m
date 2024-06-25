classdef termWeights
    
    properties
        input=[1 1];
        progress=1;
        laneKeeping=1;
        obsAvoid=1;
        RL=1;
        softConstraintPenalty=1e3;

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

