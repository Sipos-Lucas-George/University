% a) need to estimate average number of files,
%    we estimate u in the case of sigma known
x = [7 7 4 5 9 9 4 12 8 1 8 7 3 13 2 1 17 7 12 5 6 2 1 13 14 10 2 4 9 11 3 5 12 6 10 7];
n = columns(x);
alpha = input('Confidence level = ');
minus1alpha = 1 - alpha;
swap_mean = mean(x);
printf('Solving 1a\n');
sigma = 5;
m1 = swap_mean - sigma/sqrt(n) * norminv(1-alpha/2);
m2 = swap_mean - sigma/sqrt(n) * norminv(alpha/2);
printf('The CI for pop. mean, when sigma is known is (%4.3f, %4.3f)\n', m1, m2);

% b) a) but sigma unknown
s = std(x);
m11 = swap_mean - s/sqrt(n) * tinv(1-alpha/2, n-1);
m22 = swap_mean - s/sqrt(n) * tinv(alpha/2, n-1);
printf('The CI for pop. mean, when sigma is unknown is (%4.3f, %4.3f)\n', m11, m22);

% c) need to estimate variance of the population
sigma2 = var(x);
aux1 = (n-1)*sigma2/chi2inv(1-alpha/2, n-1);
aux2 = (n-1)*sigma2/chi2inv(alpha/2, n-1);
m111 = sqrt(aux1);
m222 = sqrt(aux2);
printf('The CI for the variance (%4.3f, %4.3f)\n', m111, m222);
