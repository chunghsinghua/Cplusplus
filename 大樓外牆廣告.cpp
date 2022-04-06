#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

ll d[N];

ll fun(ll a[], int le, int ri)
{
    if (le >= ri)
        return 0;
    if (le + 1 == ri)
        return a[le];
    int m = distance(a, min_element(a + le, a + ri));
    ll ans = a[m] * (ri - le);
    return max({ans, fun(a, le, m), fun(a, m + 1, ri)});
}

int main()
{
    freopen("P_5_7_3.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    cout << fun(d, 0, n);

    return 0;
}
