#include <bits/stdc++.h>

using namespace std;

#define N 210
typedef long long ll;

int d[N][N];

int main()
{
    freopen("Q_6_5_5.in", "r", stdin);
    int m, n, t;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> t;
            d[i][j] += d[i][j - 1] + t;
        }
    }

    int total, mx = INT_MIN;
    for (int k = 0; k <= n; ++k)
    {
        for (int j = k + 1; j <= n; ++j)
        {
            total = 0;
            for (int i = 1; i <= m; ++i)
            {
                total += d[i][j] - d[i][k];
                mx = max(mx, total);
                if (total < 0)
                    total = 0;
            }
        }
    }
    cout << mx;
    return 0;
}
