#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

struct work
{
    int t, d;
} d[N];

bool cmp(work a, work b)
{
    if (a.t == b.t)
        return a.d > b.d;
    return a.t < b.t;
}

int main()
{
    freopen("Q_4_16_1.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i].t;
    for (int i = 0; i < n; ++i)
        cin >> d[i].d;
    sort(d, d + n, cmp);
    ll ans = 0, psum = 0;
    for (int i = 0; i < n; ++i)
    {
        psum += d[i].t;
        ans += d[i].d - psum;
    }
    cout << ans;
    return 0;
}
