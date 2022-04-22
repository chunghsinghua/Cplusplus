#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

ll d[N];

int main()
{
    freopen("P_5_7_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    d[0] = d[n + 1] = -1;
    stack<ll> s;
    s.push(0);
    ll mx = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        if (d[i] > d[s.top()])
            s.push(i);
        if (d[i] == d[s.top()])
            continue;
        while (d[i] < d[s.top()])
        {
            ll height = d[s.top()];
            s.pop();
            mx = max(mx, height * (i - s.top() - 1));
        }
        if (d[i] > d[s.top()])
            s.push(i);
    }
    cout << mx;
    return 0;
}
