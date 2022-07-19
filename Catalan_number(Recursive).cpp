#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

ll p = 1e9 + 9;

ll fun(int n)
{
    if (n < 2)
        return 1;
    ll ret = 0;
    for (int i = 0; i < n; ++i)
    {
        ll t = fun(i) * fun(n - 1 - i) % p;
        ret = (ret + t) % p;
    }

    return ret;
}

int main()
{
    freopen("P_6_11_1.in", "r", stdin);
    int n;
    cin >> n;
    cout << fun(n);
    return 0;
}
