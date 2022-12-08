#include <bits/stdc++.h>

using namespace std;

#define N 110
typedef long long ll;

int mat[N][N];

int main()
{
    // freopen("P_8_2_5.in", "r", stdin);
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> gost;
    for (int i = 0; i < k; ++i)
    {
        vector<int> instance;
        int t;
        for (int j = 0; j < 4; ++j)
        {
            cin >> t;
            instance.push_back(t);
        }
        gost.push_back(instance);
    }

    while (gost.size() > 0)
    {
        vector<vector<int>> temp;
        for (auto e : gost)
        {
            int si = e[0], sj = e[1];
            if (mat[si][sj])
                mat[si][sj] = -1;
            else
                temp.push_back(e);
        }
        gost.swap(temp);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == -1)
                    mat[i][j] = 0;

        temp.clear();
        for (auto e : gost)
        {
            int si = e[0], sj = e[1];
            mat[si][sj] = 1;
            int ni = si + e[2], nj = sj + e[3];
            if (((ni >= 0) && (ni <= m)) && ((nj >= 0) && (nj <= n)))
            {
                e[0] = ni, e[1] = nj;
                temp.push_back(e);
            }
        }
        gost.swap(temp);
    }

    int cnt = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cnt += mat[i][j];

    cout << cnt;
    return 0;
}
