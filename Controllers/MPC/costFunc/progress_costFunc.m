function cost = progress_costFunc(X, waypoints, weight)

    target=waypoints(1,1:2)';

    cost=0;
    for i=1:size(X,1)
        x=X(i,1);
        y=X(i,2);
        yaw=X(i,3);
        speed=X(i,4);

        % Rotation matrix for transforming to the vehicle's local frame
        R = [cosd(-yaw), -sind(-yaw); sind(-yaw), cosd(-yaw)];

        target_relative=target-[x;y];
        target_relative=R * target_relative;

        cost = cost + target_relative'*weight*target_relative;
    end
end

