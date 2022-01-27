#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

struct work
{
    ll t, w;
} job[N];

bool cmp(work a, work b)
{
    return a.t * b.w < a.w * b.t;
}

int main()
{
    freopen("P_4_5_4.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> job[i].t;
    for (int i = 0; i < n; ++i)
        cin >> job[i].w;
    sort(job, job + n, cmp);
    ll ans = 0, psum = 0;
    for (int i = 0; i < n; ++i)
    {
        psum += job[i].t;
        ans += psum * job[i].w;
    }
    cout << ans;

    return 0;
}
