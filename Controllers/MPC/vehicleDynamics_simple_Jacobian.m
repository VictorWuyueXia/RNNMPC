function [J_state, J_input] = vehicleDynamics_Simple_Jacobian(state, input, ...
    Ts, L, waypoints, weights)

    % Unpack the state and input
    x = state(1);
    y = state(2);
    yaw = state(3);
    v = state(4);

    steer = input(1);
    acc = input(2);
    
    % Wheelbase of the vehicle in meters
    L = egoCar_params.Dynamics.lf+egoCar_params.Dynamics.lr; 
    
    % Pre-computed J_state expression
    J_state=[1, 0, -Ts*v*sind(yaw, Ts*cosd(yaw)); 
        0, 1, Ts*v*cosd(yaw, Ts*sind(yaw)); 
        0, 0, 1, (Ts*tand(steer))/L; 
        0, 0, 0, 1];

    % Pre-computed J_input expression
    J_input=[0, 0; 
        0, 0; 
        (Ts*v*(tand(steer)^2 + 1))/L, 0; 
        0, Ts];
end
