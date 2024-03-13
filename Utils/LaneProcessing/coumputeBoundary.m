function y = coumputeBoundary(lane, X)
    % Initialize output array
    x = X(:,1);
    y = ones(size(x)).*1e-3;

    curvature=lane(1);
    curvatureDerivative=lane(2);
    curveLength=lane(3);
    headingAngle=lane(4);
    lateralOffset=lane(5);
    
    % Initial conditions for the curve
    y(1) = lateralOffset; % Initial y position
    theta = headingAngle; % Initial heading angle
    
    
    % Discretize curve length into segments corresponding to x values
    dx=diff(x,1,1);
    dx = [0;dx]; % Segment length as difference of x values
    for i = 2:size(dx,1)
        % Assuming small angle changes, update position based on current segment
        x(i) = x(i-1) + dx(i)*cosd(theta);
        y(i) = y(i-1) + dx(i)*sind(theta);
        
        % Update heading based on curvature
        dTheta = curvature * dx(i); % Change in angle, simplified approximation
        theta = theta + dTheta;
        
        % Update curvature for next segment if needed
        curvature = curvature + curvatureDerivative * dx(i); % Simplified, assumes linear curvature change
    end
end