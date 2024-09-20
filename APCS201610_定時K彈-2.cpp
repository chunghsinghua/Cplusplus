#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> dp(k + 1, 0);
    for (int i = k - 1; i >= 0; --i)
    {
        dp[i] = (dp[i + 1] + m) % (n - i);
    }
    cout << dp[0] + 1;
    return 0;
}
