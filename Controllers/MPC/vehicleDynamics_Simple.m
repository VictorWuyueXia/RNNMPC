function nextState = vehicleDynamics_Simple(state, input, ...
    Ts, egoCar_params, waypoints, boundaries, ...
    tracks, costFun_weights)

    % Unpack the state and input
    x = state(1);
    y = state(2);
    yaw = state(3);
    v = state(4);

    steer = input(1);
    acc = input(2);
    
    % Wheelbase of the vehicle in meters
    L = egoCar_params.Dynamics.lf + egoCar_params.Dynamics.lr; 

    % Vehicle dynamics equations - continuous
    dx = v*cosd(yaw);
    dy = v*sind(yaw);
    dyaw = v*tand(steer)/L;
    dv = acc;

    % Euler's method
    x1=x+dx*Ts;
    y1=y+dy*Ts;
    yaw1=yaw+dyaw*Ts;
    v1=v+dv*Ts;

    % Return the next state
    nextState = [x1;y1;yaw1;v1];
end
