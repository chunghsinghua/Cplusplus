#include <bits/stdc++.h>

using namespace std;

#define N 75
typedef long long ll;

bool fun(ll value)
{
    while (value)
    {
        if (value % 2)
            return false;
        value /= 10;
    }
    return true;
}

int main()
{
    // freopen("P_5_7_2.in", "r", stdin);
    int n, k;
    cin >> n;
    while (n--)
    {
        cin >> k;
        ll low = 1, high = 1;
        for (int i = 0; i < k; ++i)
            high *= 10;
        low = high / 10;
        ll v = 1;
        for (int i = 0; i < (k + 1) / 2 - 1; ++i)
            v *= 10;

        for (; v * v < high; v++)
        {
            if (v * v < low)
                continue;
            if (fun(v * v))
            {
                cout << v * v << "\n";
                break;
            }
        }
    }
    return 0;
}
