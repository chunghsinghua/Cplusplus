#include <bits/stdc++.h>

using namespace std;

#define N 160000
typedef long long ll;

int main()
{
    // freopen("P_7_10_5.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> d(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    vector<int> p(n, 0), q(n, 0);
    p[0] = d[0];
    for (int i = 1; i < n; ++i)
        p[i] = max(0, p[i - 1]) + d[i];
    for (int j = 1; j <= k; ++j)
    {
        q[0] = max(d[0], 0);
        for (int i = 1; i < n; ++i)
            q[i] = max(q[i - 1] + d[i], p[i - 1]);
        p.swap(q);
    }
    int mx = 0;
    for (int e : p)
        mx = max(mx, e);
    cout << mx;
    return 0;
}
