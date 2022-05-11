for (int j = 0; j < N; ++j)
    d[j] *= 4;
for (int i = 0; i < N - 1; ++i)
{
    d[i + 1] += d[i] / 10;
    d[i] %= 10;
}
