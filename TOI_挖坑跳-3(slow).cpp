#include <bits/stdc++.h>

using namespace std;

#define N 510
typedef long long ll;

int mat[N][N], p[N][N];
int mx, wtotal, wcnt, mxtotal;
int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

int dfs(int i, int j, int root)
{
    p[i][j] = root;
    int cnt = 1;
    for (int k = 0; k < 4; ++k)
    {
        int ni = i + di[k], nj = j + dj[k];
        if (mat[ni][nj] && p[ni][nj] != root)
            cnt += dfs(ni, nj, root);
    }
    return cnt;
}

int main()
{
    freopen("P_7_10_4.in", "r", stdin);
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> mat[i][j];
    memset(p, -1, sizeof(p));
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (mat[i][j] && p[i][j] == -1)
            {
                wcnt++;
                mx = max(mx, dfs(i, j, i * N + j));
            }
        }
    }
    wtotal = wcnt;
    mxtotal = mx;
    while (k--)
    {
        int i, j;
        cin >> i >> j;
        if (mat[i][j])
            continue;
        mat[i][j] = 1;
        wcnt++;
        int temp[4];
        for (int dir = 0; dir < 4; ++dir)
            temp[dir] = p[i + di[dir]][j + dj[dir]];
        sort(temp, temp + 4);
        if (temp[0] >= 0)
            wcnt--;
        for (int dir = 1; dir < 4; ++dir)
            if (temp[dir] >= 0 && temp[dir] != temp[dir - 1])
                wcnt--;
        mx = max(mx, dfs(i, j, i * N + j));
        mxtotal += mx;
        wtotal += wcnt;
    }
    cout << mxtotal << '\n'
         << wtotal;
    return 0;
}
