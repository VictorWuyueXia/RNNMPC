function nextState = vehicleDynamics_Simple(state, input, ...
    Ts, L, waypoints, weights, limits, ...
    laneCoords, types)

    % Unpack
    % [x_pos, y_pos, yaw_direction, speed]
    x = state(1);
    y = state(2);
    yaw = state(3);
    v = state(4);

    acc = input(1);
    steer = input(2);

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
