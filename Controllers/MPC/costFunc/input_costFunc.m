function cost = input_costFunc(X,U,weight)
    
    acc=U(:,1);
    steer=U(:,2);

    v=X(:,4);
    vacc=v.*acc;

    weight_acc=weight(1,1).*eye(size(U,1));
    weight_steer=weight(2,2).*eye(size(vacc,1));

    % quadratic cost for inputs
    cost= vacc'*weight_acc*vacc + ...
        steer'*weight_steer*steer;
end