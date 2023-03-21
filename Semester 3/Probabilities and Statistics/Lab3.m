miu = input('Please enter value for miu: ');
sigma = input('Please enter value for sigma: ');
% a) P(X <= 0), P(X >=0)
resA1 = normcdf(0, miu, sigma)
resA2 = 1 - resA1
% b) P(-1 <= x <= 1) = F(1) - F(-1)
resB1 = normcdf(1, miu, sigma) - normcdf(-1, miu, sigma)
resB2 = 1 - resB1

% norminv(alpha, miu, sigma), norminv(1 - beta, miu, sigma)
alpha = input('Please enter value for alpha [0, 1]: ');
beta = input('Please enter value for beta [0, 1]: ');
resC1 = norminv(alpha, miu, sigma)
resC2 = norminv(1 - beta, miu, sigma)

