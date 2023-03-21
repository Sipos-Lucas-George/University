alpha = 0.05;
standard = [46 37 39 48 47 44 35 31 44 37];
new = [35 33 31 35 34 30 27 32 31 31];

len = length(standard);

[h, p, ci, stats] = vartest2(standard, new, 'alpha', alpha);
b1 = finv(1-alpha/2, len - 1, len - 1);
b2 = finv(alpha/2, len - 1, len - 1);
RR = [b2, b1];
if(h == 1)
  printf('The null hyp H0 is rejected\n'); % cannot be modified
  printf('The data suggests that the efficiency standard is not met\n'); % can be modified
else
  printf('The null hyp H0 is not rejected\n'); % cannot be modified
  printf('The data suggests that the efficiency standard is met\n'); % can be modified
endif
printf('The rejected region is (-inf,%4.4f) U (%4.4f, inf)\n', RR(1), RR(2));
printf('The value of the of the test statistic stats is %4.4f\n', stats.fstat);
printf('The p-value of the test is %4.4f\n', p);

mean_diff = mean(standard) - mean(new);
se = sqrt((std(standard)^2 + std(new)^2)/len);

bound = tinv(1-alpha/2, len - 1);
ci = [mean_diff - bound*se, mean_diff + bound*se];
printf('0.95 cofindence interval for the difference of average assembling times: (%g, %g)\n', ci);
