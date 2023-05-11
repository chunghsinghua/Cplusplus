#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int d[N], dp[N];

int main()
{
    freopen("Q_6_12_5.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    dp[0] = d[0];
    for (int i = 1; i <= k; ++i)
        for (int j = 0; j < i; ++j)
            dp[i] = max(d[i], dp[j]);
    for (int i = k + 1; i < n; ++i)
        dp[i] = max(dp[i - 1], d[i] + dp[i - k - 1]);
    cout << dp[n - 1];
    return 0;
}
