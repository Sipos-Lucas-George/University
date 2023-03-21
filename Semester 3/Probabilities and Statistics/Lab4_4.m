% d)
clear
n = input('Please enter value for n: ');
p = input('Please enter value for p: ');
N = input('Please enter value for N: ');
for i = 1:N
    for j = 1:n
      X(j) = 0;
      while rand >= p
        X(j) = X(j) + 1;
      endwhile
    endfor
    Y(i) = sum(X);
endfor
K = 0:150;
U_Y = unique(Y);
n_Y = hist(Y, length(U_Y));
rel_freq = n_Y / N;

plot(U_Y, rel_freq, "b*", K, geopdf(K,p), "r*")
legend("simulation", "binopdf");
