function cost = input_costFunc(X,U,weight)
    % quadratic cost for inputs
    cost=0;
    for i=1:size(U,1)
        u=U(i,:)';
        v=X(i,4);
        cost = cost + v^2*(u'*weight*u);
        % cost = cost + u'*weight*u;
    end
end