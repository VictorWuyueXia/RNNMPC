function constraints = inequalityConstraints(state, input , e, data, params)

    % Unpack
    Ts=data.Ts;
    N = data.PredictionHorizon;
    L=params.L;
    waypoints=params.waypoints;
    weights=params.weight;

    % [state stateRate input inpuRate LaneKeeping obsAvoid]

    % State is [x y yaw speed(v)]
    % Constraint is on v
    stateCon=[];



    stateRateCon=input_costFunc(u, weights(1:2,1:2));
    inputCon=0;
    inpuRateCon=0;
    LaneKeepingCon=0;
    obsAvoidCon=0;
    
    constraints= [state stateRate input inpuRate LaneKeeping obsAvoid]';
end