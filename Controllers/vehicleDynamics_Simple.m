function stateDot = vehicleDynamics_Simple(state, input)
    % Unpack the state and input
    x = state(1);
    y = state(2);
    vx = state(3);
    vy = state(4);
    yaw = state(5);
    yaw_rate = state(6);
    
    steering_angle = input(1);
    longitudinal_acc = input(2);

    L = 3; % Wheelbase of the vehicle in meters

    % Vehicle dynamics equations
    dx = vx;
    dy = vy;
    dvx = longitudinal_acc;
    dvy = (vx * tan(steering_angle)) / L;
    dyaw = yaw_rate;
    dyaw_rate = (vx * tan(steering_angle)) / (L^2);

    % Return the derivative of the state
    stateDot = [dx; dy; dvx; dvy; dyaw; dyaw_rate];
end
