#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_5_4_3.in", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int h, w, n, r, c, t, x;
    cin >> h >> w >> n;
    vector<vector<int>> mat(h, vector<int>(w, 0));
    while (n--)
    {
        cin >> r >> c >> t >> x;
        for (int i = r - t; i <= r + t; ++i)
        {
            for (int j = c - t; j <= c + t; ++j)
            {
                if (i >= 0 && j >= 0 && i < h && j < w && (abs(i - r) + abs(j - c)) <= t)
                    mat[i][j] += x;
            }
        }
    }
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
            cout << mat[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
