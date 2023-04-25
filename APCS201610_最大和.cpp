#include <bits/stdc++.h>
using namespace std;

#define N 15
typedef long long ll;

int main()
{
    // freopen("P_8_14_5.in", "r", stdin);
    int m, n, t, sum = 0;
    cin >> n >> m;
    vector<int> sel;
    for (int i = 0; i < n; ++i)
    {
        int mx = -1;
        for (int j = 0; j < m; ++j)
        {
            cin >> t;
            mx = max(mx, t);
        }
        sum += mx;
        sel.push_back(mx);
    }
    cout << sum << '\n';
    int cnt = 0;
    for (int e : sel)
        if (sum % e == 0)
        {
            cout << e << ' ';
            cnt++;
        }
    if (!cnt)
        cout << -1;
    return 0;
}
