psum[0]=0;

for (int i = 1; i <= n; ++i)
{
    cin >> d[i];
    psum[i] = d[i] + psum[i - 1];
}
