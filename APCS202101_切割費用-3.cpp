#include <bits/stdc++.h>
using namespace std;

#define N 510
typedef long long ll;

int main()
{
    // freopen("Q_3_12_5.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    ll tot = 0;
    set<pair<int, int>> s, vec;
    s.insert({0, l});
    int idx, p, le, ri;
    for (int i = 0; i < n; ++i)
    {
        cin >> p >> idx;
        vec.insert({idx, p});
    }
    for (auto e : vec)
    {
        p = e.second;
        auto it = prev(s.lower_bound({p, 0}));
        le = it->first, ri = it->second;
        tot += (ri - le);
        s.erase(it);
        s.insert({le, p}), s.insert({p, ri});
    }
    cout << tot;
    return 0;
}
