#include <bits/stdc++.h>

using namespace std;

#define N 105
typedef long long ll;

ll d[N];

int main()
{
    freopen("Q_2_10_3.in", "r", stdin);
    ll n, p;
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    set<ll> s1;
    s1.insert(d[0]);
    ll ans = d[0];
    for (int i = 1; i < n; ++i)
    {
        set<ll> s2(s1);
        for (auto e : s1)
        {
            ll t = e + d[i];
            if (t <= p)
                s2.insert(t);
        }
        s2.insert(d[i]);
        s2.swap(s1);
    }
    cout << *s1.rbegin();
    return 0;
}
