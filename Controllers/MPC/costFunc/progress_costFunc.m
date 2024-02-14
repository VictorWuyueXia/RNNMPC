function cost = progress_costFunc(X, waypoints, weight)

    target=waypoints(1,1:2)';

    x=X(1);
    y=X(2);
    yaw=X(3);
    speed=X(4);

    % Rotation matrix for transforming to the vehicle's local frame
    R = [cos(-yaw), -sin(-yaw); sin(-yaw), cos(-yaw)];
    
    target_relative=target-[x;y];
    target_relative=R * target_relative;

    cost=target_relative'*weight*target_relative;
end

