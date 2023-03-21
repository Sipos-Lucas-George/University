p = input('Enter value for p: ');
n = input('Enter value for n: ');
k = 0:3;
bp = binopdf(k,n,p);
plot(bp)

hold on
k = 0:0.1:3;
bc = binocdf(k,n,p);
plot(bc, 'g')


