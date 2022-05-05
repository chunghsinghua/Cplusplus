#include <bits/stdc++.h>

using namespace std;

#define N 105
typedef long long ll;

int dp[N];

int fun(int n)
{
    if (dp[n] > 0)
        return dp[n];
    dp[n] = dp[n - 1] + dp[n - 2];
    return dp[n];
}

int main()
{
    // freopen("P_5_7_2.in", "r", stdin);
    int n;
    cin >> n;
    dp[1] = 1, dp[2] = 2;
    cout << fun(n);
    return 0;
}
