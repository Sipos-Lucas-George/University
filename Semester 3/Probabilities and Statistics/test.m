brandA = [29.8 30.6 29.0 27.7 29.9 29.6 30.5 31.1 30.2 28.1 29.4 28.5];
brandB = [31.5 30.2 31.2 29.0 31.4 31.1 32.5 33.0 31.3 30.9 30.7 29.9];

% lenght of brand A and brand B (sample size)
n = columns(brandA);

% a)
% significance level
alpha = 0.05;

% we are using vartest2 with two-tailed test, to test the ratio of variances
[h, p, _, stats] = vartest2(brandA, brandB, 'alpha', alpha);
% rejection region
% we are using fischer distribution = finv()
RR = [finv(alpha/2, n - 1, n - 1), finv(1 - alpha/2, n - 1, n - 1)];

if(h == 1)
  printf('The null hyp H0 is rejected\n');
  printf('The data suggests that the variances of brand A and brand B differ\n');
else
  printf('The null hyp H0 is not rejected\n');
  printf('The data suggests that the variances of brand A and brand B do not differ\n');
endif
printf('The rejected region is (-inf, %g) U (%g, +inf)\n', RR);
printf('The value of the of the test statistic stats is %4.4f\n', stats.fstat);
printf('The p-value of the test is %4.4f\n', p);

% b)
% mean() =  sample mean
mean_diff = mean(brandA) - mean(brandB);
% std = sample standard deviation
se = sqrt((std(brandA)^2 + std(brandB)^2)/n);

% we are using student distribution = tinv()
bound = tinv(1-alpha/2, n - 1);
% ci = confidence interval
ci = [mean_diff - bound*se, mean_diff + bound*se];
printf('0.95 cofindence interval for the difference of average printing time: (%g, %g)\n', ci);

% we are using ttest2 with left-tailed test, to test if brand A prints faster than brand B on average
[h, p, _, stats] = ttest2(brandA, brandB, 'alpha', alpha, 'tail', 'left');
RR = [-inf, tinv(alpha, n - 1)];
if(h == 1)
  printf('The null hyp H0 is rejected\n');
  printf('The data suggests that brand A prints slower on average\n');
else
  printf('The null hyp H0 is not rejected\n');
  printf('The data suggests that brand A prints faster on average\n');
endif
printf('The rejected region is (%g, %g)\n', RR);
printf('The value of the of the test statistic stats is %4.4f\n', stats.tstat);
printf('The p-value of the test is %4.4f\n', p);






