function cost = input_costFunc(u,weight)
    % quadratic cost for inputs
    cost =u'*weight*u;
end