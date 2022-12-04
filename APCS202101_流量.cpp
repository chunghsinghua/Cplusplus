#include <bits/stdc++.h>

using namespace std;

#define N 60
typedef long long ll;

int q[N][N], qq[N][N], c[N];

int main()
{
    // freopen("P_7_4_5.in", "r", stdin);
    int m, n, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> q[i][j];

    int mn = INT_MAX;
    while (k--)
    {
        for (int i = 0; i < n; ++i)
            cin >> c[i];

        memset(qq, 0, sizeof(qq));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                qq[c[i]][j] += q[i][j];

        int cost = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
                if (i == j)
                    cost += qq[i][j];
                else
                {
                    if (qq[i][j] <= 1000)
                        cost += qq[i][j] * 3;
                    else
                        cost += 3000 + (qq[i][j] - 1000) * 2;
                }

        mn = min(mn, cost);
    }
    cout << mn;
    return 0;
}
