#include <bits/stdc++.h>

using namespace std;

#define N 105
typedef long long ll;

int d[N][N];

int main()
{
    // freopen("P_5_7_2.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        d[m][1] = 1;
    for (int i = 1; i <= n; ++i)
        d[1][i] = 1;

    for (int i = 2; i <= m; ++i)
        for (int j = 2; j <= n; ++j)
            d[i][j] = d[i - 1][j] + d[i][j - 1];

    cout << d[m][n];
    return 0;
}
