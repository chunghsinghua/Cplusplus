#include <bits/stdc++.h>

using namespace std;

#define N 20
typedef long long ll;

ll dp[N][10];
string s;

int dlen(string &str, int len)
{
    int i;
    for (i = len - 2; i >= 0; --i)
        if (str[i] < str[i + 1])
            break;
    if (i < 0)
        return len;
    for (int j = i; j >= 0; --j)
        str[j] = 9;
    int j = i + 1;
    str[j]--;
    while (len > 0 && str[len - 1] == 0)
    {
        len--;
        str.pop_back();
    }
    return len;
}

int bd(int len, int n)
{
    if (dp[len][n] >= 0)
        return dp[len][n];
    dp[len][n] = 0;
    for (int k = n; k < 10; ++k)
        dp[len][n] += bd(len - 1, k);
    return dp[len][n];
}

int main()
{
    freopen("P_6_19_3.in", "r", stdin);
    cin >> s;
    int len = s.size();
    for (int i = 0, j = len - 1; i < j; ++i, --j)
        swap(s[i], s[j]);
    for (int i = 0; i < len; ++i)
        s[i] -= '0';
    len = dlen(s, len);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = dp[1][0] = 0;
    for (int i = 1; i <= 9; ++i)
        dp[1][i] = 1;

    int t = bd(len + 1, 0);

    reverse(s.begin(), s.end());
    int ans = 0;
    for (int i = 0; i < s[0]; ++i)
        ans += dp[len][i];
    for (int i = 1; i < len; ++i)
        for (int j = s[i - 1]; j < s[i]; ++j)
            ans += dp[len - i][j];
    cout << ans + 1;
    return 0;
}
