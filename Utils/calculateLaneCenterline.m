function centerlineWaypoints = calculateLaneCenterline(curvatureLeft, curvelengthLeft, headingangleLeft, lateraloffsetLeft, curvatureRight, curvelengthRight, headingangleRight, lateraloffsetRight, targetCruiseSpeed)
    % Calculate the average curvature, curve length, heading angle, and lateral offset
    curvature = (curvatureLeft + curvatureRight) / 2;
    curvelength = (curvelengthLeft + curvelengthRight) / 2;
    headingangle = (headingangleLeft + headingangleRight) / 2;
    lateraloffset = (lateraloffsetLeft + lateraloffsetRight) / 2;

    % Estimate the optimal number of waypoints
    % Assuming a reasonable update interval (e.g., 1 second)
    updateInterval = 0.1; % seconds
    distancePerUpdate = targetCruiseSpeed * updateInterval;
    numPoints = max(10, ceil(curvelength / distancePerUpdate)); % Ensure at least 10 points for very short curves

    % Preallocate array for waypoints
    centerlineWaypoints = zeros(numPoints, 2); % [x, y] format

    % Generate waypoints along the centerline
    for i = 1:numPoints
        t = (i - 1) / (numPoints - 1); % Normalized distance along the lane

        % Calculate x and y coordinates of the centerline waypoints
        x = curvelength * t * cos(headingangle);
        y = curvelength * t * sin(headingangle) + lateraloffset;

        centerlineWaypoints(i, :) = [x, y];
    end
end
