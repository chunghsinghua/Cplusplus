#include <bits/stdc++.h>
using namespace std;

#define N 200010
typedef long long ll;

int d[N], dp[N];

int main()
{
    freopen("Q_6_12_5.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    for (int i = 0; i < n; ++i)
    {
        if (i <= k)
            dp[i] = *max_element(d, d + i + 1);
        else
            dp[i] = max(dp[i - 1], d[i] + dp[i - k - 1]);
    }
    cout << dp[n - 1];
    return 0;
}
