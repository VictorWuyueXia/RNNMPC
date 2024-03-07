function yValues = computeLanePoints(xValues, clothoid)
    % Extract necessary properties from the clothoidLaneBoundary class
    C0 = clothoid.Curvature; % Initial curvature
    Cs = clothoid.CurvatureDerivative; % Rate of change of curvature
    L = clothoid.CurveLength; % Length of the curve
    theta0 = clothoid.HeadingAngle; % Initial heading angle
    yOffset = clothoid.LateralOffset; % Lateral offset
    
    % Assuming the initial point of the curve is at (0,yOffset)
    x0 = 0;
    y0 = yOffset; % Initial y is based on lateral offset
    
    % Preallocate yValues array for performance
    yValues = NaN(size(xValues));
    
    % Loop through each xValue to compute its corresponding yValue
    for i = 1:length(xValues)
        x = xValues(i);

        if x > L
            break
        end
        
        % Linear approximation for small angles and curvatures
        % Calculate arc length s from x assuming theta is small and constant
        s = x - x0; % Approximation assuming small curvature
        
        % Calculate curvature at s
        C = C0 + Cs * s;
        
        % Update heading angle based on curvature
        % theta(s) = theta0 + integral(C0 + Cs * s)ds from 0 to s
        theta = theta0 + (C0 * s + 0.5 * Cs * s^2);
        
        % Calculate y position based on theta and curvature
        % For small theta, y(s) ≈ y0 + sin(theta) * s
        y = y0 + sind(theta) * s; % Simplified approximation
        
        % Store the calculated y-value
        yValues(i) = y;
    end
end

