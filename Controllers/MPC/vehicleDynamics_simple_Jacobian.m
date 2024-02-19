function [J_state, J_input] = vehicleDynamics_Simple_Jacobian(state, input, ...
    Ts, L, waypoints, weights)

    % Unpack the state and input
    % [x_pos, y_pos, yaw_direction, speed]
    x = state(1);
    y = state(2);
    yaw = state(3);
    v = state(4);

    acc = input(1);
    steer = input(2);
    
    % Pre-computed J_state expression
    J_state=[1, 0, -Ts*v*sind(yaw), Ts*cosd(yaw)
        0, 1, Ts*v*cosd(yaw), Ts*sind(yaw)
        0, 0, 1, (Ts*tand(steer))/L
        0, 0, 0, 1];

    % Pre-computed J_input expression
    J_input=[0, 0; 
        0, 0; 
        (Ts*v*(tand(steer)^2 + 1))/L, 0; 
        0, Ts];
end
