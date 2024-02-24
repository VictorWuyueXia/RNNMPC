function traj = ScenarioCenterline(data)
    % Set tracking trajectory as the road centerline
    centerline=data.RoadSpecifications.Centers;
    
    deltas = diff(centerline, 1, 1); % Differences between consecutive points
    distances = sqrt(sum(deltas.^2, 2)); % Euclidean distances
    totalDistance = sum(distances); % Total path length
    
    % Generate Time Stamps Based on Target Speed
    timeStamps = [0; cumsum(distances) / targetSpeed];
    
    % Position (already available as centerline points)
    positionSeries = centerline;
    
    % traj=positionSeries;
    
    % Velocity (constant speed along the trajectory)
    velocitySeries = targetSpeed * deltas ./ distances;
    velocitySeries = [velocitySeries(1, :); velocitySeries]; % Replicate first velocity
    
    % Orientation (as yaw angles)
    yawAngles = atan2(deltas(:, 2), deltas(:, 1));
    yawSeries = [yawAngles(1); yawAngles]; % Replicate first yaw angle
    
    traj = timeseries([positionSeries velocitySeries yawSeries],timeStamps);
end