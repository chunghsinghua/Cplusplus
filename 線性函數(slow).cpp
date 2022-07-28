#include <bits/stdc++.h>

using namespace std;

#define N 100010
#define M 50010
typedef long long ll;

pair<ll, ll> line[N];
ll c[M];

int main()
{
    freopen("Q_3_14_5.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> line[i].first >> line[i].second;
    for (int i = 0; i < m; ++i)
        cin >> c[i];
    sort(line, line + n);
    sort(c, c + m);
    ll mx = LLONG_MIN, idx = 0;
    ll sum = 0;
    for (int i = 0; i < m; ++i)
    {
        mx = LLONG_MIN;
        for (int j = idx; j < n; ++j)
        {
            ll t = c[i] * line[j].first + line[j].second;
            if (t > mx)
            {
                mx = t;
                idx = j;
            }
        }
        sum += mx;
    }
    cout << sum;
    return 0;
}
