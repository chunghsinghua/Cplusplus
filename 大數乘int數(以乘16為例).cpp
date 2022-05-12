int carry = 0;
for (int j = 0; j < N; ++j)
{
    d[j] = d[j] * 16 + carry;
    carry = d[j] / 10;
    d[j] %= 10;
}
