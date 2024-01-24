function [leftBoundary, rightBoundary] = BoundariesCordinates_Ego(laneData)
    % Assuming laneData is a struct from the Vision Detection Generator output

    % Extracting lane boundaries (adjust indexing based on your data structure)
    leftLane = laneData.LaneBoundaries(1);
    rightLane = laneData.LaneBoundaries(2);

    % Converting clothoidLaneBoundary objects to line equations in vehicle coordinates
    % This is a simplified example. You'll need to adjust this based on your specific needs
    leftBoundary = convertToLineEquation(leftLane);
    rightBoundary = convertToLineEquation(rightLane);
end

function lineEq = convertToLineEquation(laneBoundary)
    % Convert a lane boundary object to a line equation
    % Here, a simple linear approximation is used. For more accuracy, use clothoid parameters

    % Example linear equation: y = mx + c
    m = tan(laneBoundary.HeadingAngle); % Slope from heading angle
    c = laneBoundary.LateralOffset; % Intercept from lateral offset

    lineEq = struct('slope', m, 'intercept', c);
end
