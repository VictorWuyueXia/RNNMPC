function constraints = inequalityConstraints(X, U, e, data, ...
    Ts, L, waypoints, weights, limits, ...
    NumLanes, laneVector)
    %% Make inequality constraints
    % [ieqCon1
    %  ieqCon2-e] <=0

    % Unpack
    N = data.PredictionHorizon;
    % lastMV=data.LastMV;
    
    % [speedMAX accMAX jerkMAX brakeMAX turnAngleMAX turnAngleRateMAX]
    speedMax=limits(1);
    reverseMax=limits(2);
    accMax=limits(3);
    jerkMax=limits(4);
    brakeMax=limits(5);
    steerMax=limits(6);
    steerRateMax=limits(7);

    % Xs are PredictionHorizon rows and 4 columns
    % The first row is the current X, which cannot be changed
    x=X(:,1);
    y=X(:,2);
    yaw=X(:,3);
    v=X(:,4);

    % Inputs are PredictionHorizon rows and 2 columns
    % The last row is duplicated for the final step
    acc=U(:,1);
    steer=U(:,2);

    % [X{speed} XRate{G-force, G-force jerk} input inpuRate ...
    % LaneKeeping obsAvoid}]

    %% State 
    % [x y yaw speed(v)]

    stateCon=[v-speedMax-e;
        -v+reverseMax-e]; % speed
    
    %% StateRate

    % yawRate=deg2rad(diff(yaw))./Ts;
    % turnRadius=abs(v(2:N+1)./yawRate); % r=v/omega
    % turnRadius(isnan(turnRadius))=1e3;% in case yawRate==0
    % centriAcc=v(2:N+1).*2./turnRadius; % a=v^2/r
    % centriAcc(isnan(centriAcc))=0;% in case turnRadius==0
    % % totalAcc=(centriAcc.^2 + linearAcc.^2).*0.5; % a=sqrt(al^2+ar^2)
    % 
    % centriJerk=diff(centriAcc);
    % 
    % stateRateCon=[abs(centriAcc)-accMax-e; % G-force
    %     abs(centriJerk)-jerkMax-e]; % G-force jerk
    
    stateRateCon=-1;

    %% Input 
    % [acc steer(deg)]
    inputCon=[acc-accMax; % linear acc
        -brakeMax-acc;
        steer.^2-steerMax.^2]; % steer

    %% InputRate
    % linearJerk=diff(acc(1:N+1))./Ts;
    % steerRate=diff(steer(1:N+1))./Ts;
    % 
    % inpuRateCon=[abs(linearJerk)-jerkMax; % linear jerk
    %     abs(steerRate)-steerRateMax]; % steer rate

    inpuRateCon=-1;
    %% Lane Keeping
    LaneKeepingCon=laneKeepingCon(X, e, NumLanes, laneVector);

    %% Obstacle Avoidance
    obsAvoidCon=-1;
    
    %% Sum
    constraints= [stateCon;stateRateCon;inputCon;inpuRateCon;LaneKeepingCon;obsAvoidCon];
end