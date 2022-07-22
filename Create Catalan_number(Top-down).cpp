#include <bits/stdc++.h>

using namespace std;

#define N 110
typedef long long ll;

ll dp[N];
ll p = 1e9 + 9;

ll fun(int n)
{
    if (dp[n] >= 0)
        return dp[n];
    ll ret = 0;
    for (int i = 0; i < n; ++i)
    {
        ll t = fun(i) * fun(n - 1 - i) % p;
        ret = (ret + t) % p;
    }

    return dp[n] = ret;
}

int main()
{
    freopen("P_6_11_5.in", "r", stdin);
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    int n;
    cin >> n;
    cout << fun(n);
    return 0;
}
