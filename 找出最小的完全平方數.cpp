#include <bits/stdc++.h>

using namespace std;

#define N 75
typedef long long ll;

bool fun(int value, int div)
{
    while (value)
    {
        int t = value / div;
        if (t % 2)
            return false;
        value %= div;
        div /= 10;
    }
    return true;
}

int main()
{
    // freopen("P_5_7_2.in", "r", stdin);
    int n, k;
    cin>>n;
    while (n--)
    {
        cin >> k;
        int low = 1, high = 1;
        for (int i = 0; i < k; ++i)
            high *= 10;
        low = high / 10;
        int v = 1;
        for (int i = 0; i < (k + 1) / 2 - 1; ++i)
            v *= 10;

        for (; v * v < high; v++)
        {
            if (v * v < low)
                continue;
            if (fun(v * v, low))
            {
                cout << v * v;
                break;
            }
        }
    }
    return 0;
}
