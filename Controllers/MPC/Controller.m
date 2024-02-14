classdef Controller
    % An MPC controller
    
    properties
        controller
        weights
        model
        jacobian
        costFunc
        optimizer

    end
    
    methods
        function obj = Controller(controller)
            obj.controller=controller;
        end
    end
end

