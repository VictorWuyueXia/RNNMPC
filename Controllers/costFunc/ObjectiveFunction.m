function cost = ObjectiveFunction(X, U ,e, data, ...
    Ts, L, waypoints, weights, limits, ...
    NumLanes, laneVector)

    % Unpack
    % weights is fed in as an 2xN array of 
    % [input(1x2) progress(1x1) laneKeeping(1x1) obsAvoid(1x1) RL(1x1) softConstraintPenalty(1x1)]
    weightInput = weights(1:2);
    weightProgress = weights(3);
    weightLaneKeeping = weights(4);
    % weightObsAvoid = weights(5);
    weightRL = weights(6);
    weightSoftConstraintPenalty = weights(7);
    
    cost_progress=progressTerm(X, waypoints, weightProgress);
    cost_inputs=inputTerm(X, U, weightInput);
    % cost_laneKeeping=laneKeepingTerm(X, NumLanes, laneVector, weightLaneKeeping);
    cost_laneKeeping=0;

    cost_obstacleAvoidance=0;
    cost_RL=0;
    cost_softConstraints=e*weightSoftConstraintPenalty;
    
    cost= cost_progress + ...
        cost_inputs + ...
        cost_laneKeeping + ...
        cost_obstacleAvoidance + ...
        cost_RL + ...
        cost_softConstraints;
end