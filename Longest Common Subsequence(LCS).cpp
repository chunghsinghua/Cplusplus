#include <bits/stdc++.h>

using namespace std;

#define N 510
typedef long long ll;

int dp[N][N];

int main()
{
    freopen("P_6_7_2.in", "r", stdin);
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.size(), len2 = s2.size();

    for (int i = 0; i < N; ++i)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for (int i = 1; i <= len2; ++i)
    {
        for (int j = 1; j <= len1; ++j)
        {
            if (s1[j - 1] == s2[i - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }
    cout << dp[len2][len1];
    return 0;
}
