function cost = laneKeeping_costFunc(X, laneCoords, weight)
    % quadratic cost for difference in distance from each boundary
    cost=0;
    pointPair=1;
    for i=1:size(X,1)
        x=X(i,:)'; % one state
        
        % The current lane boundaries points pair
        Distance_l = norm(laneCoords(pointPair,1)-x(1:2));
        Distance_r = norm(laneCoords(pointPair,2)-x(1:2));

        totalDistance = Distance_l + Distance_r;
        diffDistance = Distance_l - Distance_r;
        
        % Find the nearest point pair
        while pointPair < size(laneCoords,1) % if the last pair, stop; 
            
            % The next lane boundaries points pair
            Distance_l_next = norm(laneCoords(pointPair+1,1)-x(1:2));
            Distance_r_next = norm(laneCoords(pointPair+1,2)-x(1:2));
    
            totalDistance_next = Distance_l_next + Distance_r_next;
            diffDistance_next = Distance_l_next - Distance_r_next;

            if isnan(totalDistance_next) % if next is NaN, stop; 
                break
            end
            
            if ~(totalDistance_next < totalDistance)% if next is further, stop; 
                break
            end
            
            totalDistance=totalDistance_next;
            diffDistance=diffDistance_next;
            pointPair=pointPair+1;
        end

        cost=cost + diffDistance^2*weight;
    end
end