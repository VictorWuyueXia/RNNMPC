function cost = input_costFunc(X,U,weight)
    
    acc=U(:,1);
    steer=U(:,2);

    v=X(:,4);
    vs=steer.*v;

    weight_acc=weight(1,1).*eye(size(acc,1));
    weight_steer=weight(2,2).*eye(size(steer,1));

    % quadratic cost for inputs
    cost= acc'*weight_acc*acc + ...
        vs'*weight_steer*vs;
end