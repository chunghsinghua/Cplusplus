#include <bits/stdc++.h>

using namespace std;

#define N 110
typedef long long ll;

int d[N][N];

// space : 0
// - : 1
// | : 2
// +: 3
// stop : 4

int m, n, h;

void add(int r, int c)
{
    if (d[r][c] != 1 && d[r][c] != 3) // important!!
    {
        int c2 = c - 1;
        while (c2 >= 0 && d[r][c2] != 4)
            c2--;
        if (c2 >= 0)
        {
            for (int i = c - 1; i > c2; --i)
                d[r][i] += 1;
        }
        c2 = c + 1;
        while (c2 < n && d[r][c2] != 4)
            c2++;
        if (c2 < n)
        {
            for (int i = c + 1; i < c2; ++i)
                d[r][i] += 1;
        }
    }

    if (d[r][c] != 2 && d[r][c] != 3) // important!!
    {
        int r2 = r - 1;
        while (r2 >= 0 && d[r2][c] != 4)
            r2--;
        if (r2 >= 0)
        {
            for (int i = r - 1; i > r2; --i)
                d[i][c] += 2;
        }
        r2 = r + 1;
        while (r2 < m && d[r2][c] != 4)
            r2++;
        if (r2 < m)
        {
            for (int i = r + 1; i < r2; ++i)
                d[i][c] += 2;
        }
    }
    d[r][c] = 4;
}
void rem(int r, int c)
{
    d[r][c] = 0;
    int c2 = c - 1;
    while (c2 >= 0 && (d[r][c2] == 1 || d[r][c2] == 3))
    {
        d[r][c2] -= 1;
        c2--;
    }
    c2 = c + 1;
    while (c2 < n && (d[r][c2] == 1 || d[r][c2] == 3))
    {
        d[r][c2] -= 1;
        c2++;
    }
    int r2 = r - 1;
    while (r2 >= 0 && (d[r2][c] == 2 || d[r2][c] == 3))
    {
        d[r2][c] -= 2;
        r2--;
    }
    r2 = r + 1;
    while (r2 < m && (d[r2][c] == 2 || d[r2][c] == 3))
    {
        d[r2][c] -= 2;
        r2++;
    }
}

int main()
{
    // freopen("Q_3_13_5.in", "r", stdin);
    cin >> m >> n >> h;
    int p, q, r;
    int mx = 0, current;
    for (int b = 0; b < h; ++b)
    {
        cin >> p >> q >> r;
        if (r == 1)
            rem(p, q);
        else
        {
            add(p, q);
        }
        current = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                current += (d[i][j] != 0);
        mx = max(mx, current);
    }
    cout << mx << "\n"
         << current << "\n";

    return 0;
}
