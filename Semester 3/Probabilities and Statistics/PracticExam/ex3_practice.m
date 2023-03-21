np = [3.26 1.89 2.42 2.03 3.07 2.95 1.39 3.06 2.46 3.35 1.56 1.79 1.76 3.82 2.42 2.96];

n = columns(np);
alpha = 0.05;
npmean = mean(np);
npstd = std(np);
sd = tinv(1-alpha/2, n-1);

bound = [npmean - npstd*sd/(sqrt(n)), npmean + npstd*sd/(sqrt(n))];

printf("%g %g\n", bound)

alpha = 0.01;
mu = 3;
[h, p, ci, stats] = ttest(np, mu, 'alpha', alpha, 'tail', 'left');
RR = [-inf, tinv(alpha, n - 1)];
if(h == 1)
  printf('The null hyp H0 is rejected\n');
  printf('The data suggests that on average the nickel particles do not seem to be smaller than 3\n');
else
  printf('The null hyp H0 is not rejected\n');
  printf('The data suggests that on average the nickel particles seem to be smaller than 3\n');
endif
printf('The rejected region is (%g, %g)\n', RR);
printf('The value of the of the test statistic stats is %4.4f\n', stats.tstat);
printf('The p-value of the test is %4.4f\n', p);

