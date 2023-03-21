p = input('Enter value for p [0.05, 0.95]: ');
for n = 1:25:250
  k = 0:n; % number of successes
  y = binopdf(k, n, p);
  plot(k, y)
  pause(0.3);
  endfor
