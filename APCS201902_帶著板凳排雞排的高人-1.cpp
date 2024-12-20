#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    freopen("Q_3_5_3.in", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    vector<pair<int, int>> stk;
    stk.push_back({-1e9, 0});
    ll tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        int idx = distance(stk.begin(), lower_bound(stk.begin(), stk.end(), make_pair(-h[i] - p[i], 0))) - 1;
        tot += i - stk[idx].second - 1;
        while (stk.back().first >= -h[i])
            stk.pop_back();
        stk.push_back({-h[i], i});
    }
    cout << tot;
    return 0;
}
