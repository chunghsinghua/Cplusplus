#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_2_15_3.in", "r", stdin);
    int n, dir;
    cin >> n >> dir;
    dir -= 1;
    if (dir < 0)
        dir += 4;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];
    int dr[4] = {0, -1, 0, 1}, dc[4] = {-1, 0, 1, 0};
    int rr = n / 2, cc = n / 2;
    cout << mat[rr][cc];
    int step = 1;
    for (int k = 1; k <= n; ++k)
    {
        for (int kk = 1; kk <= 2; ++kk)
        {
            dir = (dir + 1) % 4;

            for (int j = 1; j <= k; ++j)
            {
                rr += dr[dir], cc += dc[dir];
                cout << mat[rr][cc];
                if (++step == n * n)
                {
                    cout << '\n';
                    return 0;
                }
            }
        }
    }
}
