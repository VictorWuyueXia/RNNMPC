function cost = progressTerm(X, target, weight)
    % waypoints are in body frame
    target=repmat(target, [size(X,1),1]);
    
    % state positions
    position=X(:,1:2);

    % relative position to the target waypoint
    dPosition=position - target;
    
    % relative distance away with the waypoint 
    distance=vecnorm(dPosition')';
    
    distance0=distance(1);
    distance1=distance(end);

    progress=distance1/distance0;

    if isnan(progress)
        progress=0;
    end
    
    cost = progress' * weight * progress;
end

