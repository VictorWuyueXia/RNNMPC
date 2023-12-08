function cost = mpcCostFunction(currentState, controlInput, waypoints, targetCruiseSpeed, weights)
    % Unpack weights
    inputWeights = weights.inputWeights; % Weights for control input

    % Find the nearest waypoint
    nearestWaypoint = findNearestWaypoint(currentState, waypoints);

    % Calculate position error
    positionError = currentState(1:2) - nearestWaypoint(1:2); % Assuming first two states are x and y
    positionCost = sum(positionError .^ 2);

    % Calculate speed error
    currentSpeed = sqrt(currentState(3)^2 + currentState(4)^2); % Assuming third and fourth states are vx and vy
    speedError = currentSpeed - targetCruiseSpeed;
    speedCost = speedError^2;

    % Calculate weighted square of the control inputs
    weightedControlInput = inputWeights .* controlInput;
    inputCost = sum(weightedControlInput .^ 2);

    % Sum the costs
    cost = positionCost + speedCost + inputCost;
end