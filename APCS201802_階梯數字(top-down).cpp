#include <bits/stdc++.h>

using namespace std;

#define N 210
typedef long long ll;

int dp[N][10];
int fun1(string &str, int len)
{
    int i;
    for (i = len - 2; len >= 0; --i)
    {
        if (str[i] < str[i + 1])
            break;
    }
    if (i < 0)
        return len;

    for (int j = i; j >= 0; --j)
        str[j] = 9;
    int j = i + 1;
    str[j]--;
    while (j < len && str[j] < str[j + 1])
    {
        str[j] = 9;
        j++;
        str[j]--;
    }
    while (str.back() == 0)
    {
        str.pop_back();
        len--;
    }
    // for (int k = len - 1; k >= 0; --k)
    //     cout << (int)str[k]; //check
    return len;
}

int fun2(int len, int start)
{
    if (dp[len][start] >= 0)
        return dp[len][start];
    dp[len][start] = 0;
    for (int i = start; i <= 9; ++i)
        dp[len][start] += fun2(len - 1, i);

    return dp[len][start];
}

int main()
{
    freopen("P_6_19_5.in", "r", stdin);
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; ++i)
        s[i] -= '0';
    for (int i = 0, j = len - 1; i < j; ++i, --j)
        swap(s[i], s[j]);
    len = fun1(s, len);

    memset(dp, -1, sizeof(dp));
    dp[1][0] = 0;
    for (int i = 1; i <= 9; ++i)
        dp[1][i] = 1;
    int t = fun2(len + 1, 0);

    int ans = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s[0]; ++i)
        ans += dp[len][i];
    for (int i = 1; i < len; ++i)
        for (int j = s[i - 1]; j < s[i]; ++j)
            ans += dp[len - i][j];

    cout << ans + 1;
    return 0;
}
