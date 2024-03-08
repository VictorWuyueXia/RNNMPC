function laneKeepingIneq = laneKeepingCon(X, e, ...
    laneBoundaryDetectionRange, laneCoords, laneTypes)
    
    % types: BoundaryType
    % 0 for no markings (i.e. some road edges)
    % 1 for solid lines
    % 2 for dashed lines
    % 5 for double solid lines
    laneKeepingIneq=[];

    sign=[1,-1]; % for lanekeeping inEq constraints calculation 
    
    for laneIndex=1:2 % for each lane
        if laneTypes(laneIndex)==0 % if there is no lane to detect
            break
        end

        for step=1:size(X,1) % for each step of states
            x=X(1);
            y=X(2);
            yaw=X(3);
            v=X(4);
            
            if X>max(laneCoords(laneIndex,:)) % if the lane is too short
                break
            end
            

        end
    end

end

