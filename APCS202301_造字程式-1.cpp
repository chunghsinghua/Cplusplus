#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int main()
{
    // freopen("P_8_3_5.in", "r", stdin);
    int k, q, r;
    cin >> k >> q >> r;
    string s;
    cin >> s;
    s = "0" + s;
    vector<string> t(q, string(k + 1, '0'));
    int newidx;
    for (int i = 0; i < q; ++i)
    {
        for (int idx = 1; idx <= k; ++idx)
        {
            cin >> newidx;
            t[i][newidx] = s[idx];
        }
        s = t[i];
    }
    for (int i = 1; i <= r; ++i)
    {
        for (auto e : t)
            cout << e[i];
        cout << '\n';
    }
    return 0;
}
