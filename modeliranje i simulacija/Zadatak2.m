x = [-2: 0.2: 2];
y = [-1: 0.1: 1];

[X,Y] = meshgrid(x,y);

Z = X .* exp(-X.^2-Y.^2);

figure;
surf(X,Y,Z);

figure;
mesh(X,Y,Z);

figure;
fill3(X,Y,Z,'r');