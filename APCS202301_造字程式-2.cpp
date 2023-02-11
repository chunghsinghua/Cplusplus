#include <bits/stdc++.h>

using namespace std;

#define N 10005
typedef long long ll;

int main()
{
    // freopen("P_7_12_2.in", "r", stdin);
    int k, q, r;
    cin >> k >> q >> r;
    string s;
    cin >> s;
    s = '0' + s;
    vector<string> ret;
    for (int i = 0; i < q; ++i)
    {
        string t(k + 1, '0');
        int newidx;
        for (int idx = 1; idx <= k; ++idx)
        {
            cin >> newidx;
            t[newidx] = s[idx];
        }
        ret.push_back(t);
        swap(s, t);
    }
    for (int i = 1; i <= r; ++i)
    {
        for (string e : ret)
            cout << e[i];
        cout << '\n';
    }
    return 0;
}
