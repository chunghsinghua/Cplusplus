#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_4_13_5.in", "r", stdin);
    int n;
    cin >> n;
    ll mxsum = 0;
    ll pmx = 0;
    ll t;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        if (pmx > 0)
            pmx += t;
        else
            pmx = t;
        mxsum = max(mxsum, pmx);
    }
    cout << mxsum;
    return 0;
}
