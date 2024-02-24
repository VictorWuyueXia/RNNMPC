function cost = mpcCostFunction(X, U ,e, data, ...
    Ts, L, waypoints, weights, limits)

    % Unpack
    % weights is fed in as an array of 
    % [progress_x progress_y input_acc input_steer obsAvoid LaneKeeping RL sofConstraints]
    cost_progress=progress_costFunc(X, waypoints, weights(1,3));
    cost_inputs=input_costFunc(U, weights(1:2,1:2));
    cost_obstacleAvoidance=0;
    cost_laneKeeping=0;
    cost_RL=0;
    cost_softConstraints=e*weights(1,end);
    
    cost= cost_progress + ...
        cost_inputs + ...
        cost_laneKeeping + ...
        cost_obstacleAvoidance + ...
        cost_RL + ...
        cost_softConstraints;
end