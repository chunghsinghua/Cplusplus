#include <bits/stdc++.h>

using namespace std;

#define N 75
typedef long long ll;

int d[N];

void power(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        int carry = 0;
        for (int j = 0; j < N; ++j)
        {
            d[j] = d[j] * 4 + carry;
            carry = d[j] / 10;
            d[j] %= 10;
        }
    }
}

void divide(int n)
{
    int r = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        r = r * 10 + d[i];
        d[i] = r / n;
        r = r % n;
    }
}

int main()
{
    // freopen("P_5_7_2.in", "r", stdin);
    int n;
    cin >> n;
    d[0] = 1;
    power(n);
    d[0] -= 1;
    divide(3);

    int idx = N - 1;
    while (d[idx] == 0)
        idx--;
    while (idx >= 0)
        cout << d[idx--];

    return 0;
}
