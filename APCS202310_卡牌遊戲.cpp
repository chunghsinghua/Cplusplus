#include <bits/stdc++.h>

using namespace std;

#define N 60
typedef long long ll;

int mat[N][N];

int main()
{
    // freopen("P_7_6_1.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mat[i][j];
    bool check = true;
    int total = 0;
    while (check)
    {
        check = false;
        for (int s = 0; s < n; ++s)
        {
            for (int t = 0; t < m; ++t)
            {
                if (mat[s][t] < 0)
                    continue;
                int i;
                for (i = s + 1; i < n && mat[i][t] < 0; ++i)
                    ;
                if (i < n && mat[i][t] == mat[s][t])
                {
                    total += mat[s][t];
                    mat[i][t] = mat[s][t] = -1;
                    check = true;
                    continue;
                }
                int j;
                for (j = t + 1; j < m && mat[s][j] < 0; ++j)
                    ;
                if (j < m && mat[s][j] == mat[s][t])
                {
                    total += mat[s][j];
                    mat[s][j] = mat[s][t] = -1;
                    check = true;
                    continue;
                }
            }
        }
    }
    cout << total;
    return 0;
}
