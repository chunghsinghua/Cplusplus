#include <bits/stdc++.h>

using namespace std;

#define N 300010
typedef long long ll;

int mat[52][N];

int main()
{
    freopen("Q_2_12_2.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n, k;
    cin >> k >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> mat[i][j];
            mat[i][j] += mat[i][j - 1];
        }
    int ans = 0;
    for (int p = 0; p <= n; ++p)
    {
        for (int j = p + 1; j <= n; ++j)
        {
            int sum = 0;
            for (int i = 1; i <= m; ++i)
            {
                sum += mat[i][j] - mat[i][p];
                if (sum <= k)
                    ans = max(ans, sum);
                if (sum < 0)
                    sum = 0;
            }
        }
    }
    cout << ans;
    return 0;
}
