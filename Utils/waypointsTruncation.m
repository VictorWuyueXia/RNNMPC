function waypoints = waypointsTruncation(pos, vel, waypoints)
    % Discard the passed waypoints

    pos=pos(1:2);
    vel=vel(1:2);
    
    % Track the first waypoint
    currentWaypoint=waypoints(1,1:2);

    % distance from the waypoint
    distance=norm(currentWaypoint-pos);
    
    % Passed waypoints are either within 1m of the ego car
    % or 1second away of the ego car
    perimeter=norm(vel.*1);
    perimeter=min(1,perimeter);
    
    if size(waypoints,1) > 1
        if distance<perimeter && ~isnan(waypoints(2,1))
            waypoints=[waypoints(2:end,1:2); NaN NaN];
        end
    end
end

