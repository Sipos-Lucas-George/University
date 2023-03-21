% b)
clear
n = input('Please enter value for n: ');
p = input('Please enter value for p: ');
N = input('Please enter value for N: ');
for i = 1:N
  U = rand(n,1);
  X(i) = sum(U < p);

  endfor
K = 0:n;
U_X = unique(X);
n_X = hist(X, length(U_X));
rel_freq = n_X/N;
plot(U_X, rel_freq, "b*", K, binopdf(K, n, p), "r*")
legend("simulation", "binopdf");
