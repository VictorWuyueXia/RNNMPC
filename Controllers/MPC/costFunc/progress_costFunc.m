function cost = progress_costFunc(X, waypoints, weight)
    % waypoints are in body frame
    target=waypoints(1,1:2)';

    cost=0;
    for i=1:size(X,1)
        pos=X(i,1:2)';
        distance=norm(target-pos);

        cost = cost + distance'*weight*distance;
    end
end

