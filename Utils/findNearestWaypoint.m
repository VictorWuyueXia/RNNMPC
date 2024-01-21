function nearestWaypoint = findNearestWaypoint(currentState, waypoints)
    % Initialize variables
    minDistance = inf;
    nearestWaypoint = waypoints(1, :);

    % Loop through waypoints to find the nearest one
    for i = 1:size(waypoints, 1)
        waypoint = waypoints(i, :);
        distance = norm(currentState(1:2) - waypoint(1:2)) + abs(currentState(5) - waypoint(3)); % Assuming 5th state is yaw
        if distance < minDistance
            minDistance = distance;
            nearestWaypoint = waypoint;
        end
    end
end