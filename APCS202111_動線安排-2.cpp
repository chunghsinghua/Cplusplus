#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;
// 0:empty, 1:vertical, 2:horizontal, 3:cross, 4:site
int m, n, h, r, c, op, cnt = 0, mx = 0;
void add(vector<vector<int>> &mat, int r, int c)
{
    if (mat[r][c] == 1 || mat[r][c] == 0)
    {
        int c2 = c - 1;
        while (c2 >= 0 && mat[r][c2] != 4)
            c2--;
        if (c2 >= 0 && mat[r][c2] == 4)
            for (int j = c2 + 1; j <= c - 1; ++j)
                mat[r][j] += 2;
        c2 = c + 1;
        while (c2 < n && mat[r][c2] != 4)
            c2++;
        if (c2 < n && mat[r][c2] == 4)
            for (int j = c2 - 1; j >= c + 1; --j)
                mat[r][j] += 2;
    }
    if (mat[r][c] == 2 || mat[r][c] == 0)
    {
        int r2 = r - 1;
        while (r2 >= 0 && mat[r2][c] != 4)
            r2--;
        if (r2 >= 0 && mat[r2][c] == 4)
            for (int i = r2 + 1; i <= r - 1; ++i)
                mat[i][c] += 1;
        r2 = r + 1;
        while (r2 < m && mat[r2][c] != 4)
            r2++;
        if (r2 < m && mat[r2][c] == 4)
            for (int i = r2 - 1; i >= r + 1; --i)
                mat[i][c] += 1;
    }
    mat[r][c] = 4;
}

void remove(vector<vector<int>> &mat, int r, int c)
{
    mat[r][c] = 0;
    int c2 = c - 1;
    while (c2 >= 0 && (mat[r][c2] == 3 || mat[r][c2] == 2))
    {
        mat[r][c2] -= 2;
        c2--;
    }
    c2 = c + 1;
    while (c2 < n && (mat[r][c2] == 3 || mat[r][c2] == 2))
    {
        mat[r][c2] -= 2;
        c2++;
    }
    int r2 = r - 1;
    while (r2 >= 0 && (mat[r2][c] == 3 || mat[r2][c] == 1))
    {
        mat[r2][c] -= 1;
        r2--;
    }
    r2 = r + 1;
    while (r2 < m && (mat[r2][c] == 3 || mat[r2][c] == 1))
    {
        mat[r2][c] -= 1;
        r2++;
    }
}

int main()
{
    // freopen("q_1_8_5.in", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> m >> n >> h;
    vector<vector<int>> mat(m, vector<int>(n, 0));
    while (h--)
    {
        cnt = 0;
        cin >> r >> c >> op;
        if (op == 0)
            add(mat, r, c);
        else
            remove(mat, r, c);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] != 0)
                    cnt++;
        mx = max(mx, cnt);
    }
    cout << mx << '\n'
         << cnt;
    return 0;
}
