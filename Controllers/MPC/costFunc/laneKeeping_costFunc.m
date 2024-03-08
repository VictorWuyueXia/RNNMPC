function cost = laneKeeping_costFunc(X, laneBoundaryDetectionRange, laneCoords, weight)
    
% quadratic cost for difference in distance from each boundary
x_coord=laneBoundaryDetectionRange;
cost=0;
pointPair=1;
for i=1:size(X,1)
    xi=X(i,:); % one state
    
    % The current lane boundaries points pair
    Point_l=[x_coord(pointPair) laneCoords(pointPair,1)];
    Point_r=[x_coord(pointPair) laneCoords(pointPair,2)];

    Distance_l = norm(xi(1:2)-Point_l);
    Distance_r = norm(xi(1:2)-Point_r);

    totalDistance = Distance_l + Distance_r;
    diffDistance = Distance_l - Distance_r;
    
    % Find the nearest point pair
    while pointPair < size(laneCoords,1) % if the last pair, stop; 
        
        % The next lane boundaries points pair
        Point_l_next=[x_coord(pointPair+1) laneCoords(pointPair+1,1)];
        Point_r_next=[x_coord(pointPair+1) laneCoords(pointPair+1,2)];

        Distance_l_next = norm(xi(1:2)-Point_l_next);
        Distance_r_next = norm(xi(1:2)-Point_r_next);

        totalDistance_next = Distance_l_next + Distance_r_next;
        diffDistance_next = Distance_l_next - Distance_r_next;

        if isnan(totalDistance_next) % if next is NaN, stop; 
            break
        end
        
        if totalDistance_next >= totalDistance% if next is further, stop; 
            break
        end
        
        totalDistance=totalDistance_next;
        diffDistance=diffDistance_next;
        pointPair=pointPair+1;
    end

    cost=cost + (totalDistance^2+diffDistance^2)*weight;
end
