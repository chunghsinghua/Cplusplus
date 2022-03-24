#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int d[N];

ll subarr(int a[], int le, int ri)
{
    if (le >= ri)
        return 0;
    if (le + 1 == ri)
        return max(0, a[le]);
    int m = (le + ri) >> 1;
    ll twomax = max(subarr(a, le, m), subarr(a, m, ri));
    ll lmax = 0, rmax = 0;
    for (ll sum = 0, i = m - 1; i >= le; --i)
    {
        sum += a[i];
        lmax = max(lmax, sum);
    }
    for (ll sum = 0, i = m; i < ri; ++i)
    {
        sum += a[i];
        rmax = max(sum, rmax);
    }
    return max(twomax, lmax + rmax);
}

int main()
{
    freopen("P_4_13_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    cout << subarr(d, 0, n);
    return 0;
}
