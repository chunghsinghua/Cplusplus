#include <bits/stdc++.h>

using namespace std;

#define N 10000000
typedef long long ll;

ll w[N], dp[N];

ll fun(int m, int n)
{
    if (dp[m] >= 0)
        return dp[m];
    ll mx = 0;
    for (int i = 0; i < n; ++i)
    {
        ll k;
        if (m & (1 << i))
        {
            k = fun(m ^ (1 << i), n);
            mx = max(mx, k);
        }
    }
    return dp[m] = w[m] + mx;
}

int main()
{
    freopen("P_6_20_5.in", "r", stdin);
    int n;
    cin >> n;
    int m = (1 << n);
    for (int i = 0; i < m; ++i)
        cin >> w[i];
    memset(dp, -1, sizeof(dp));
    dp[0] = w[0];
    cout << fun(m - 1, n);
    return 0;
}
