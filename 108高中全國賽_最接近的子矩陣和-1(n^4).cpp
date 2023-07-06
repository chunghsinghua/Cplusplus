
#include <bits/stdc++.h>

using namespace std;

#define N 210
typedef long long ll;

int mat[60][7000];

int main()
{
    freopen("Q_2_12_2.in", "r", stdin);
    int k, m, n;
    cin >> k >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> mat[i][j];
            mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
        }
    int t, ans = INT_MIN;
    for (int si = 1; si <= m; ++si)
    {
        for (int sj = 1; sj <= n; ++sj)
        {
            for (int i = si; i <= m; ++i)
            {
                for (int j = sj; j <= n; ++j)
                {
                    t = mat[i][j] - mat[si - 1][j] - mat[i][sj - 1] + mat[si - 1][sj - 1];
                    if (t <= k)
                        ans = max(ans, t);
                }
            }
        }
    }
    cout << ans;
    return 0;
}
