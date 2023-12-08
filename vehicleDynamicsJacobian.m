function J = vehicleDynamicsJacobian(state, input)
    vx = state(3);
    steering_angle = input(1);

    L = 3; % Wheelbase of the vehicle

    % Initialize the Jacobian matrix
    J = zeros(6, 8);

    % Partial derivatives
    J(3, 3) = 1; % dvx/dvx
    J(3, 8) = 1; % dvx/da
    J(4, 3) = tan(steering_angle) / L; % dvy/dvx
    J(4, 7) = (vx / (cos(steering_angle)^2)) / L; % dvy/dδ
    J(6, 3) = tan(steering_angle) / (L^2); % dyaw_rate/dvx
    J(6, 7) = (vx / (cos(steering_angle)^2)) / (L^2); % dyaw_rate/dδ

    % Other derivatives are zero and are already initialized
end
