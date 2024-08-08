#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

struct Monster
{
    int r, c, s, t;
};

int main()
{
    // freopen("p_1_1_5.in", "r", stdin);
    int m, n, k, r, c, s;
    cin >> m >> n >> k;
    vector<vector<int>> bmat(m, vector<int>(n, 0));
    vector<Monster> monster(k), monster2;
    for (int i = 0; i < k; ++i)
    {
        cin >> monster[i].r >> monster[i].c >> monster[i].s >> monster[i].t;
    }

    while (!monster.empty())
    {
        monster2.clear();
        for (auto e : monster)
        {
            bmat[e.r][e.c] = 1;
            int nr = e.r + e.s, nc = e.c + e.t;
            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if (bmat[nr][nc])
            {
                bmat[nr][nc] = -1;
                continue;
            }

            e.r = nr, e.c = nc;
            monster2.push_back(e);
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (bmat[i][j] == -1)
                    bmat[i][j] = 0;
        monster.swap(monster2);
    }
    int cnt = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (bmat[i][j])
                cnt++;
    cout << cnt;
    return 0;
}
