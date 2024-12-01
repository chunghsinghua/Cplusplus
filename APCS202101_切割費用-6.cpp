#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("Q_3_12_5.in", "r", stdin);
    int n, l, idx, pos;
    cin >> n >> l;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> pos >> idx;
        vec[idx - 1] = pos;
    }
    ll tot = 0;
    set<int> ss({0, l});
    for (int e : vec)
    {
        auto it = ss.lower_bound(e);
        tot += *it;
        tot -= *(prev(it));
        ss.insert(e);
    }
    cout << tot;
    return 0;
}
