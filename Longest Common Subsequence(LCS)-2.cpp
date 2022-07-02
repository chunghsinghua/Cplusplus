#include <bits/stdc++.h>
using namespace std;

#define N 510
typedef long long ll;

int dp[2][N];

int main()
{
    freopen("P_6_7_5.in", "r", stdin);
    string s1, s2;
    cin >> s1 >> s2;
    int from = 0, to = 1;
    int len1 = s1.size(), len2 = s2.size();
    for (int i = 1; i <= len2; ++i)
    {
        for (int j = 1; j <= len1; ++j)
        {
            if (s1[j - 1] == s2[i - 1])
                dp[to][j] = dp[from][j - 1] + 1;
            else
                dp[to][j] = max(dp[from][j], dp[to][j - 1]);
        }
        swap(from, to);
    }
    cout << dp[from][len1];

    return 0;
}
