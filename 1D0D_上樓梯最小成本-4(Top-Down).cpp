#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int dp[N], d[N];

int fun(int i)
{
    if (dp[i] > 0)
        return dp[i];
    dp[i] = min(fun(i - 1), fun(i - 2)) + d[i];
    return dp[i];
}

int main()
{
    freopen("P_6_1_3.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    dp[0] = d[0], dp[1] = d[1];
    cout << fun(n - 1);
    return 0;
}
