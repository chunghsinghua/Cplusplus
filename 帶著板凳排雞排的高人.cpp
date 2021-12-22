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
    ll ans = 0;
    multimap<int, int> mmp;
    for (int i = n; i >= 0; i--)
    {
        auto it = mmp.begin();
        while (it != mmp.end() && it->first < h[i])
        {
            ans += it->second - i - 1;
            it = mmp.erase(it);
        }
        mmp.insert({h[i] + p[i], i});
    }
    cout << ans;
    return 0;
}
