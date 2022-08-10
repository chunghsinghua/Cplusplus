#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N], dp[N];

int main()
{
    freopen("P_6_13_5.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    for (int i = 0; i < n; ++i)
    {
        if (i <= k)
            dp[i] = d[i];
        else
            dp[i] = d[i] + (*min_element(dp + max(0, i - 2 * k - 1), dp + i));
    }
    int ans = *min_element(dp + n - 1 - k, dp + n);
    cout << ans;
    return 0;
}
