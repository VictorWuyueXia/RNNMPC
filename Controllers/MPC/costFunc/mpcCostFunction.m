function cost = mpcCostFunction(x, u, y, e, Ts, L, waypoints, weights)
    
    % weights is fed in as an array of 
    % [progress_x progress_y input_acc input_steer obsAvoid LaneKeeping RL sofConstraints]
    cost_progress=progress_costFunc(x, waypoints, weights(1:2,3:4));
    cost_inputs=input_costFunc(u, weights(1:2,1:2));
    cost_obstacleAvoidance=0;
    cost_laneKeeping=0;
    cost_RL=0;
    cost_softConstraints=0;
    
    cost= cost_progress + ...
        cost_inputs + ...
        cost_laneKeeping + ...
        cost_obstacleAvoidance + ...
        cost_RL + ...
        cost_softConstraints;
end