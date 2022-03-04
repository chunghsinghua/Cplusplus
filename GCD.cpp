int gcd(int a, int b)
{
    // 令 a 比 b 大，比較容易思考。
    while (b != 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
