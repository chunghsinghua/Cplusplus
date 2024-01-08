#include <bits/stdc++.h>

using namespace std;

#define N 160000
typedef long long ll;

int main()
{
    // freopen("P_7_10_5.in", "r", stdin);
    int m, n, k, t;
    cin >> m >> n >> k;
    string mat[m];
    for (int i = 0; i < m; ++i)
        cin >> mat[i];
    vector<char> ret;
    int dr[6] = {-1, 0, 1, 1, 0, -1};
    int dc[6] = {0, 1, 1, 0, -1, -1};
    int i = m - 1, j = 0, ni, nj;
    set<char> ss;
    while (k--)
    {
        cin >> t;
        ni = i + dr[t], nj = j + dc[t];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n)
            i = ni, j = nj;
        ret.push_back(mat[i][j]);
        ss.insert(mat[i][j]);
    }
    for (char e : ret)
        cout << e;
    cout << '\n';
    cout << ss.size();
    return 0;
}
