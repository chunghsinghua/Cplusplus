#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int d[N];

int main()
{
    freopen("P_2_9_4.in", "r", stdin);
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    map<ll, ll> m1;
    m1[d[0]] = 1;
    for (int i = 1; i < n; ++i)
    {
        map<ll, ll> m2(m1);
        for (auto e : m1)
        {
            ll t = e.first * d[i] % p;
            m2[t] = (m2[t] + e.second) % p;
        }
        m2[d[i]] = (m2[d[i]] + 1) % p;
        m2.swap(m1);
    }
    cout << m1[1];
    return 0;
}
