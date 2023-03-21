p = input('Enter value for p: ');
n = input('Enter value for n: ');
k = 0:n;
y = binopdf(k,n,p);
plot(k,y)

hold on
lambda = n * p;
yp = poisspdf(k, lambda);
plot(k, yp, 'g')
