#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("Q_3_5_3.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> seq(n);
    for (int i = 0; i < n; ++i)
        cin >> seq[i].second >> seq[i].first;
    sort(seq.begin(), seq.end());
    set<int> s{0, l};
    ll tot = 0, t;
    for (int i = 0; i < n; ++i)
    {
        t = seq[i].second;
        s.insert(t);
        auto it = s.find(t);
        tot += *next(it) - *prev(it);
    }
    cout << tot;
    return 0;
}
