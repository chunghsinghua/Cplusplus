#include <bits/stdc++.h>

using namespace std;

#define N 20
typedef long long ll;

ll dp[N][10];

int main()
{
    freopen("P_6_19_5.in", "r", stdin);
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; ++i)
        s[i] -= '0';
    dp[1][0] = 0;
    for (int i = 1; i <= 9; ++i)
        dp[1][i] = 1;
    for (int i = 1; i <= len; ++i)
        dp[i][9] = 1;
    for (int i = 2; i <= len; ++i)
    {
        for (int j = 8; j >= 0; --j)
            dp[i][j] = dp[i - 1][j] + dp[i][j + 1];
    }
    ll total = 0;
    for (int i = 0; i < s[0]; ++i)
        total += dp[len][i];
    int i = 1;
    for (; i < len; ++i)
    {
        if (s[i] < s[i - 1])
            break;
        for (int j = s[i - 1]; j < s[i]; ++j)
            total += dp[len - i][j];
    }
    if (i == len)
        total++;
    cout << total;
    return 0;
}
