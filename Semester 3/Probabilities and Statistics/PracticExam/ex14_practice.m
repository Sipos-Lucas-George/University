alpha = 0.05;
steel = [4.6 0.7 4.2 1.9 4.8 6.1 4.7 5.5 5.4];
glass = [2.5 1.3 2.0 1.8 2.7 3.2 3.0 3.5 3.4];

steeln = length(steel);
glassn = length(glass);

[h, p, ci, stats] = vartest2(steel, glass, 'alpha', alpha);
b1 = finv(1-alpha/2, steeln - 1, glassn - 1);
b2 = finv(alpha/2, steeln - 1, glassn - 1);
RR = [b2, b1];
if(h == 1)
  printf('The null hyp H0 is rejected\n'); % cannot be modified
  printf('The data suggests that the efficiency standard is not met\n'); % can be modified
else
  printf('The null hyp H0 is not rejected\n'); % cannot be modified
  printf('The data suggests that the efficiency standard is met\n'); % can be modified
endif
printf('The rejected region is (-inf, %4.4f) U (%4.4f, inf)\n', RR(1), RR(2));
printf('The value of the of the test statistic stats is %4.4f\n', stats.fstat);
printf('The p-value of the test is %4.4f\n', p);

[h, p, ci, stats] = ttest2(steel, glass, 'alpha', alpha, 'tail', 'right');
z_crit = tinv(1-alpha, steeln - 1);
RR = [z_crit,inf];
if(h == 1)
  printf('The null hyp H0 is rejected\n'); % cannot be modified
  printf('The data suggests that the efficiency standard is not met\n'); % can be modified
else
  printf('The null hyp H0 is not rejected\n'); % cannot be modified
  printf('The data suggests that the efficiency standard is met\n'); % can be modified
endif
printf('The rejected region is (%4.4f %4.4f)\n', RR);
printf('The value of the of the test statistic stats is %4.4f\n', stats.tstat);
printf('The p-value of the test is %4.4f\n', p);

