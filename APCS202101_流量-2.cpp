#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("p_1_1_5.in", "r", stdin);
    int m, n, k, t, cost = 0;
    cin >> m >> n >> k;
    vector<vector<int>> q(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> q[i][j];
    int best = 1e9;
    while (k--)
    {
        vector<vector<int>> c2c(n, vector<int>(n, 0));
        cost = 0;
        for (int i = 0; i < m; ++i)
        {
            cin >> t;
            for (int j = 0; j < n; ++j)
                c2c[t][j] += q[i][j];
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    cost += c2c[i][j];
                else
                {
                    if (c2c[i][j] <= 1000)
                        cost += c2c[i][j] * 3;
                    else
                        cost += 1000 * 3 + (c2c[i][j] - 1000) * 2;
                }
            }
        }
        best = min(best, cost);
    }
    cout << best;
    return 0;
}
