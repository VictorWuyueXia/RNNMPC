function laneKeepingIneq = laneKeepingCon(X, e, ...
    NumLanes, laneVector)
    
    % types: BoundaryType
    % 0 for no markings (i.e. some road edges)
    % 1 for solid lines
    % 2 for dashed lines
    % 5 for double solid lines

    laneKeepingIneq=ones(2*size(X,1),1).*-1;
    y=X(:,2);
    boundaryTypes=laneVector(6,:);
    
    % If detected a full lane (two boundareis)
    if all(boundaryTypes)
        % left boundary
        if boundaryTypes(1)==1 % Solid
            LB_l = laneVector(:,1);
            LB_l = coumputeBoundary(LB_l, X);
            
            % Stay inside, soft constraint if solid
            % hard constraint if double solid 
            laneKeepingIneq(1:size(X,1)) = y-LB_l-e; 
        end
        if boundaryTypes(1)==5 % double solid
            LB_l = laneVector(:,1);
            LB_l = coumputeBoundary(LB_l, X);
            
            % Stay inside, soft constraint if solid
            % hard constraint if double solid 
            laneKeepingIneq(1:size(X,1)) = y-LB_l; 
        end

        % right boundary
        if boundaryTypes(2)==1 % Solid
            LB_r = laneVector(:,2);
            LB_r = coumputeBoundary(LB_r, X);

            % Stay inside, soft constraint if solid
            % hard constraint if double solid 
            laneKeepingIneq(size(X,1)+1:end) = LB_r-y-e;
        end
        if boundaryTypes(2)==5 % double solid
            LB_r = laneVector(:,2);
            LB_r = coumputeBoundary(LB_r, X);

            % Stay inside, soft constraint if solid
            % hard constraint if double solid 
            laneKeepingIneq(size(X,1)+1:end) = LB_r-y;
        end
    end
end

