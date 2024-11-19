#include <bits/stdc++.h>

using namespace std;

#define N 60
typedef long long ll;

int mat[N][N];
int main()
{
    // freopen("P_7_6_3.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mat[i][j];

    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int total = 0;
            int x = mat[i][j];
            for (int s = i - x; s <= i + x; ++s)
            {
                for (int t = j - x; t <= j + x; ++t)
                {
                    if (s >= 0 && s < n && t >= 0 && t < m && (abs(s - i) + abs(t - j) <= x))
                        total += mat[s][t];
                }
            }
            if (total % 10 == x)
                v.push_back({i, j});
        }
    }
    cout << v.size() << '\n';
    for (auto e : v)
        cout << e.first << ' ' << e.second << '\n';
    return 0;
}
