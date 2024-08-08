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
    int m, n, k;
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
            if (bmat[e.r][e.c])
                bmat[e.r][e.c] = -1;
            else
                monster2.push_back(e);
        }

        monster.swap(monster2);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (bmat[i][j] == -1)
                    bmat[i][j] = 0;

        monster2.clear();

        for (auto e : monster)
        {
            bmat[e.r][e.c] = 1;
            e.r += e.s, e.c += e.t;
            if (e.r >= 0 && e.c >= 0 && e.r < m && e.c < n)
                monster2.push_back(e);
        }
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
