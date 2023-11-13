#include <bits/stdc++.h>

using namespace std;

#define N 300010
typedef long long ll;

ll a[N], psum[N];

int main()
{
    // freopen("P_4_14_5.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }
    int le = 1, ri = n;
    ll lesum, risum, k;
    while (le != ri)
    {
        k = distance(a, min_element(a + le, a + ri + 1));
        lesum = psum[k - 1] - psum[le - 1];
        risum = psum[ri] - psum[k];
        if (lesum > risum)
            ri = k - 1;
        else
            le = k + 1;
    }
    cout << a[le];
    return 0;
}
