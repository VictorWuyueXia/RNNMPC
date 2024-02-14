function cost = input_costFun(u,weight)
    % quadratic cost for inputs
    cost =u'*weight*u;
end