function cost = progressTerm(X, target, weight)
    % waypoints are in body frame
    target=repmat(target, [size(X,1),1]);
    
    % state positions
    position=X(:,1:2);

    % relative position to the target waypoint
    dPosition=position - target;
    
    % relative distance away with the waypoint
    distance=vecnorm(dPosition')';
    
    % normalize all the distances to 0-1
    distance_normalized=distance./distance(1);
    distance_normalized(isnan(distance_normalized))=0;
    
    % Each step's progress, as how much it contributes to
    % the overall distance left, from 0-1
    progress=diff(distance_normalized);

    % quadratic cost
    progress_left=1-sum(progress);
    cost = progress_left' * weight * progress_left;
end

