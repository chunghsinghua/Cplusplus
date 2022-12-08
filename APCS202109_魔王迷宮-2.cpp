#include <bits/stdc++.h>
using namespace std;

#define N 510
typedef long long ll;

int mat[N][N];
struct Ghost
{
    int i, j, s, t;
};

int main()
{
    // freopen("P_6_20_5.in", "r", stdin);
    int m, n, k;
    cin >> m >> n >> k;
    vector<Ghost> ghost;
    for (int i = 0; i < k; ++i)
    {
        Ghost t;
        cin >> t.i >> t.j >> t.s >> t.t;
        ghost.push_back(t);
    }
    while (ghost.size())
    {
        vector<Ghost> t;
        for (auto e : ghost)
            if (mat[e.i][e.j])
                mat[e.i][e.j] = -1;
            else
                t.push_back(e);

        ghost.swap(t);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == -1)
                    mat[i][j] = 0;

        t.clear();
        for (auto e : ghost)
        {
            mat[e.i][e.j] = 1;
            e.i += e.s, e.j += e.t;
            if (((e.i >= 0) && (e.i < m)) && ((e.j >= 0) && (e.j < n)))
                t.push_back(e);
        }
        ghost.swap(t);
    }

    int cnt = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cnt += mat[i][j];

    cout << cnt;

    return 0;
}
