#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("q_1_8_5.in", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int k, q, r, t;
    cin >> k >> q >> r;
    vector<string> ret(q + 1, string(k, '0'));
    cin >> ret[0];

    for (int i = 1; i <= q; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            cin >> t;
            ret[i][t - 1] = ret[i - 1][j];
        }
    }
    for (int i = 0; i < r; ++i)
    {
        for (int j = 1; j <= q; ++j)
            cout << ret[j][i];
        cout << '\n';
    }
    return 0;
}
