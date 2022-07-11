psum[0] = d[0];

for (int i = 1; i < n; ++i)
  psum[i] = psum[i - 1] + d[i];
