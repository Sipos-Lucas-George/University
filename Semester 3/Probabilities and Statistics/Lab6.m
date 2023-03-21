% null hyp H0 miu = 9
% alt hyp H1 miu < 9
% left-tailed test for the mean
x = [7 7 4 5 9 9 4 12 8 1 8 7 3 13 2 1 17 7 12 5 6 2 1 13 14 10 2 4 9 11 3 5 12 6 10 7];
n = columns(x);
alpha = input('Significance level = ');

printf('Solving 1a)\n');
printf("We have a left-tail test for the mean in the case in the case sigma known\n");

m0 = 9;
sigma = 5;
[h, p, ci, z, zcrit] = ztest(x, m0, sigma, 'alpha', alpha, 'tail', 'left');
zz = norminv(alpha);
RR = [-inf,zz]; % rejected region for the left-tailed test
printf('h is %d\n', h);
if(h == 1)
  printf('The null hyp H0 is rejected\n'); % cannot be modified
  printf('The data suggests that the efficiency standard is not met\n'); % can be modified
else
  printf('The null hyp H0 is not rejected\n'); % cannot be modified
  printf('The data suggests that the efficiency standard is met'); % can be modified
endif
printf('The rejected region is (%4.4f, %4.4f)\n', RR(1), RR(2));
printf('The value of the of the test statistic z is %4.4f\n', z);
printf('The p-value of the test is %4.4f\n', p);
