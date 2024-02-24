function tgt_relative = world2body(pos, yaw, tgt)
    % Transform target tgt from world frame to body frame
    % yaw is in degree, pos and tgt are column vectord

    % Rotation matrix for transforming to the vehicle's local frame
    R = [cosd(-yaw), -sind(-yaw); sind(-yaw), cosd(-yaw)];
    
    tgt_dispaced=tgt-pos;
    tgt_relative=R*tgt_dispaced;
end

