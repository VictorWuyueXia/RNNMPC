classdef termWeights
    
    properties
        input=eye(2);
        progress=ones(2,1);
        laneKeeping=ones(2,1);
        obsAvoid=ones(2,1);
        RL=ones(2,1);
        softConstraintPenalty=[1e6 0]';

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

