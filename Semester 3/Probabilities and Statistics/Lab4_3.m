% c)
clear
p = input('Please enter value for p: ');
N = input('Please enter value for N: ');
for i = 1:N
  X(i) = 0;
  while rand >= p
    X(i) = X(i) + 1;
  endwhile
endfor
K = 0:20;
U_X = unique(X);
n_X = hist(X, length(U_X));
rel_freq = n_X/N;
plot(U_X, rel_freq, "b*", K, geopdf(K,p), "r*")
legend("simulation", "binopdf");
