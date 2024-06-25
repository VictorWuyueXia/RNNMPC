function cost = inputTerm(X,U,weightInput)
    
    acc=U(:,1);
    steer=U(:,2);

    v=X(:,4);
    vs=steer.*v;

    weightAcc=weightInput(1);
    weightSteer=weightInput(2);

    weight_acc=weightAcc.*eye(size(acc,1));
    weight_steer=weightSteer.*eye(size(steer,1));

    % quadratic cost for inputs
    cost= acc'*weight_acc*acc + ...
        vs'*weight_steer*vs;
end