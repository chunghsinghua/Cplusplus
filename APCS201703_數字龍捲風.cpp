#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_3_1_5.in", "r", stdin);
    int n, d;
    cin >> n >> d;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];
    // 0:le ; 1:top; 2:ri; 3:bottom;
    int dr[4] = {0, -1, 0, 1}, dc[4] = {-1, 0, 1, 0};
    int si = n / 2, sj = n / 2;
    cout << mat[si][sj];
    int base = 2;
    for (int t = 1; t < n; ++t)
    {
        if (t == n - 1)
            base = 3;
        for (int kk = 0; kk < base; ++kk)
        {
            for (int tt = 1; tt <= t; ++tt)
            {
                si += dr[d], sj += dc[d];
                cout << mat[si][sj];
            }
            d = (d + 1) % 4;
        }
    }
    cout << '\n';
    return 0;
}
