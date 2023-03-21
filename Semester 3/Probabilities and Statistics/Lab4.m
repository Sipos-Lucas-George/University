% a)
clear
p = input('Please enter value for p: ');
N = input('Please enter value for N: ');
U = rand(1,N);
X = (U < p);
U_X = unique(X);
n_X = hist(X, length(U_X));
rel_freq = n_X/N;
