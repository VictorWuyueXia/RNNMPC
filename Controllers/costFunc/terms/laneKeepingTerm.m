function cost = laneKeepingTerm(X, NumLanes, laneVector, weight)
    cost=0;
    weight_pos=weight(1)*eye(size(X,1));
    weight_yaw=weight(2)*eye(size(X,1));
    x=X(:,1);
    y=X(:,2);
    yaw=X(:,3);

    LB_l=y;
    if laneVector(6,1)~=0 % If a left boundary is detected
        LB_l = laneVector(:,1);
        LB_l = coumputeBoundary(LB_l, X);
    end

    LB_r=y;
    if laneVector(6,2)~=0 % If a right boundary is detected
        LB_r = laneVector(:,2);
        LB_r = coumputeBoundary(LB_r, X);
    end

    directions=yaw;
    if all(laneVector(6,:)) % If both boundaries are detected
        dLB_l=[diff(LB_l) diff(x);1 0];
        directions=atand(dLB_l(:,2)./dLB_l(:,1));
        directions(end,:)=directions(end-1,:);
    end

    % Minimize the both the difference and sum 
    % of distances away from both lane boundareis
    distances_l =  y- LB_l;
    distances_r =  y- LB_r;

    ddis = distances_l - distances_r;
    sdis = distances_l + distances_r;
    distances = ddis + sdis;

    cost = cost + distances'*weight_pos*distances;

    % And minimize the difference between the line direction and the car orientation
    ddir=directions-yaw;
    cost = cost + ddir'*weight_yaw*ddir;
end
