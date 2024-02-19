function cost = input_costFunc(U,weight)
    % quadratic cost for inputs
    cost=0;
    for i=1:size(U,1)
        u=U(i,:)';
        cost = cost + u'*weight*u;
    end
end