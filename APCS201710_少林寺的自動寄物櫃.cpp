#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

struct item
{
    ll w, f;
} d[N];

bool cmp(item a, item b)
{
    return a.w * b.f < a.f * b.w;
}

int main()
{
    freopen("Q_4_6_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i].w;
    for (int i = 0; i < n; ++i)
        cin >> d[i].f;

    ll pw = 0, ans = 0;
    sort(d, d + n, cmp);
    for (int i = 1; i < n; ++i)
    {
        pw += d[i - 1].w;
        ans += pw * d[i].f;
    }
    cout << ans;
    return 0;
}
