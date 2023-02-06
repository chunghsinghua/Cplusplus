#include <bits/stdc++.h>
using namespace std;

#define N 110
typedef long long ll;

int mat[N][N];

int main()
{
    freopen("P_7_3_5.in", "r", stdin);
    int n, m;
    cin >> m >> n;
    memset(mat, -1, sizeof(mat));
    int si, sj, mn = INT_MAX;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> mat[i][j];
            if (mat[i][j] < mn)
            {
                mn = mat[i][j];
                si = i, sj = j;
            }
        }

    int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
    int total = 0;
    while (1)
    {
        total += mat[si][sj];
        mat[si][sj] = -1;
        mn = INT_MAX;
        int ni, nj;
        for (int k = 0; k < 4; ++k)
        {
            int i = si + di[k], j = sj + dj[k];
            if (mat[i][j] != -1 && mat[i][j] < mn)
            {
                ni = i, nj = j;
                mn = mat[i][j];
            }
        }
        if (mn == INT_MAX)
            break;
        si = ni, sj = nj;
    }
    cout << total;
    return 0;
}
