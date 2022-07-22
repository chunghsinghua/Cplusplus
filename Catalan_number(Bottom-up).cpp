#include <bits/stdc++.h>

using namespace std;

#define N 110
typedef long long ll;

ll dp[N];
ll p = 1e9 + 9;

int main()
{
    freopen("P_6_11_3.in", "r", stdin);
    dp[0] = 1;
    int n;
    cin >> n;
    ll t = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
            dp[i] = (dp[i] + dp[j] * dp[i - 1 - j] % p) % p;
    }
    cout << dp[n];

    return 0;
}
