#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

pair<int, int> d[N];

int main()
{
    freopen("P_4_11_3.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> d[i].first >> d[i].second;
    }
    sort(d, d + n);
    ll ans = 0;
    int s = d[0].first, e = d[0].second;
    for (int i = 1; i < n; ++i)
    {
        if (d[i].first > e)
        {
            ans += (e - s);
            s = d[i].first;
            e = d[i].second;
        }
        else
        {
            e = max(e, d[i].second);
        }
    }
    ans += (e - s);
    cout << ans;
    return 0;
}
