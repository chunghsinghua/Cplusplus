#include <bits/stdc++.h>

using namespace std;

#define N 100
typedef long long ll;

int mat[N][N];

int main()
{
    // freopen("P_6_19_3.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    int mn = INT_MAX, si, sj;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> mat[i][j];
            if (mat[i][j] < mn)
            {
                mn = mat[i][j];
                si = i, sj = j;
            }
        }
    }
    for (int i = 0; i <= n + 1; ++i)
        mat[0][i] = mat[m + 1][i] = -1;
    for (int i = 0; i <= m + 1; ++i)
        mat[i][0] = mat[i][n + 1] = -1;

    int ans = 0;
    int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
    while (1)
    {
        ans += mat[si][sj];
        mat[si][sj] = -1;
        int ni = si, nj = sj;
        mn = INT_MAX;
        for (int k = 0; k < 4; ++k)
        {
            int i = si + di[k], j = sj + dj[k];
            if (mat[i][j] >= 0 && mat[i][j] < mn)
            {
                mn = mat[i][j];
                ni = i, nj = j;
            }
        }
        if (mn == INT_MAX)
            break;
        si = ni, sj = nj;
    }
    cout << ans;
    return 0;
}
