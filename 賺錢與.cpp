#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

struct Work
{
    int t, d;
} work[N];

bool cmp(Work &a, Work &b)
{
    return ((a.t < b.t) || (a.t == b.t && a.d > b.d));
    /*  if (a.t == b.t)
         return a.d > b.d;
     return a.t < b.t; */
}

int main()
{
    freopen("Q_4_16_1.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> work[i].t;
    for (int i = 0; i < n; ++i)
        cin >> work[i].d;
    sort(work, work + n, cmp);
    ll tsum = 0, total = 0;
    for (int i = 0; i < n; ++i)
    {
        tsum += work[i].t;
        total += work[i].d - tsum;
    }
    cout << total;
    return 0;
}
