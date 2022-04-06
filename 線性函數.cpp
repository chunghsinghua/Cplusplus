#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

struct line
{
    ll a, b;
} d[N];

ll c[N];

bool cmp(line a, line b)
{
    if (a.a == b.a)
        return a.b < b.b;
    return a.a < b.a;
}

ll dc(int lle, int lri, int ple, int pri)
{
    if (ple >= pri)
        return 0;
    int m = (ple + pri) >> 1;
    ll ans = LLONG_MIN, who;
    for (int i = lle; i < lri; ++i)
    {
        ll t = d[i].a * c[m] + d[i].b;
        if (t > ans)
        {
            ans = t;
            who = i;
        }
    }
    return ans + dc(lle, who + 1, ple, m) + dc(who, lri, m + 1, pri);
}

int main()
{
    freopen("Q_3_14_3.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> d[i].a >> d[i].b;
    for (int i = 0; i < m; ++i)
        cin >> c[i];
    sort(d, d + n, cmp);
    sort(c, c + m);
    cout << dc(0, n, 0, m);

    return 0;
}
