#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int h[N], p[N];

int main()
{
    freopen("Q_3_5_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
    }
    h[0] = p[0] = 20000010;
    multimap<int, int> mmp;
    mmp.insert({h[0], 0});
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        auto it = mmp.upper_bound(h[i] + p[i]);
        ans += i - (it->second) - 1;
        while (!mmp.empty() && mmp.begin()->first <= h[i])
            mmp.erase(mmp.begin());
        mmp.insert({h[i], i});
    }
    cout << ans;

    return 0;
}
