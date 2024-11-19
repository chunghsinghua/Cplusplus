#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("Q_3_12_5.in", "r", stdin);
    int h, w, n, r, c, t, x;
    cin >> h >> w >> n;
    vector<vector<int>> mat(h, vector<int>(w, 0));
    while (n--)
    {
        cin >> r >> c >> t >> x;
        for (int i = max(0, r - t); i <= min(h - 1, r + t); ++i)
        {
            for (int j = max(0, c - t); j <= min(w - 1, c + t); ++j)
            {
                if (abs(r - i) + abs(c - j) <= t)
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
