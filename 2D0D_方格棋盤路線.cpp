#include <bits/stdc++.h>

using namespace std;

#define N 210
typedef long long ll;

int d[N][N];

int main()
{
    freopen("P_6_6_5.in", "r", stdin);
    int m, n, t;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> d[i][j];

    int mx = INT_MIN;
    for (int i = 1; i <= m; ++i)
        d[i][1] += d[i - 1][1];
    for (int j = 1; j <= n; ++j)
        d[1][j] += d[1][j - 1];

    for (int i = 2; i <= m; ++i)
        for (int j = 2; j <= n; ++j)
            d[i][j] = max(d[i - 1][j], d[i][j - 1]) + d[i][j];

    cout << d[m][n];
    return 0;
}
