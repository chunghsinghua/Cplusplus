#include <bits/stdc++.h>

using namespace std;

#define N 510
typedef long long ll;

int dp[2][N];

int main()
{
    freopen("P_6_7_4.in", "r", stdin);
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.size(), len2 = s2.size();
    int idx = 0;
    for (int i = 1; i <= len2; ++i)
    {
        for (int j = 1; j <= len1; ++j)
        {
            if (s2[i] == s1[j])
                dp[idx ^ 1][j] = dp[idx][j - 1] + 1;
            else
                dp[idx ^ 1][j] = max({dp[idx][j], dp[idx ^ 1][j - 1], dp[idx][j - 1]});
        }
        idx ^= 1;
    }
    cout << dp[idx][len1];
    return 0;
}
