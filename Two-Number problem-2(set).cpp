#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int a[N], b[N];

int main()
{
    freopen("P_2_6_5.in", "r", stdin);
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    set<int> s;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        s.insert(t);
    }
    ll ans = 0;
    for (int i = 0; i < m; ++i)
    {
        if (s.find(k - a[i]) != s.end())
            ans++;
    }
    cout << ans;
    return 0;
}
