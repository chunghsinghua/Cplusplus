#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int d[N], dp[N];

int main()
{
    // freopen("P_5_7_2.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    dp[0] = d[0], dp[1] = d[1], dp[2] = d[2] + min(d[0], d[1]);
    for (int i = 3; i < n; ++i)
        dp[i] = d[i] + min({dp[i - 1], dp[i - 2], dp[i - 3]});

    cout << min(dp[n - 1], dp[n - 2]);
    return 0;
}
