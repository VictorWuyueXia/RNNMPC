function cost = progressTerm(X, waypoints, weight)
    % waypoints are in body frame
    target=waypoints(1,1:2);
    target=repmat(target, [size(X,1),1]);

    position=X(:,1:2);

    dPosition=target-position;

    distance=vecnorm(dPosition')';

    progress=diff(distance);

    % Linear cost
    progress_sum=sum(-progress);
    cost = weight*progress_sum;
end

