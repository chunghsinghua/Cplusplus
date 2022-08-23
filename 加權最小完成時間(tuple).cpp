#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int main()
{
    freopen("P_4_5_3.in", "r", stdin);
    int n;
    cin >> n;
    vector<tuple<double, ll, ll>> d;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        d.push_back({0, t, 0});
    }
    for (int i = 0; i < n; ++i)
    {
        int w;
        cin >> w;
        get<2>(d[i]) = w;
        if (w == 0)
            get<0>(d[i]) = 10001.0;
        else
            get<0>(d[i]) = (double)get<1>(d[i]) / w;
    }
    sort(d.begin(), d.end());
    ll sumt = 0, total = 0;
    for (int i = 0; i < n; ++i)
    {
        sumt += get<1>(d[i]);
        total += sumt * get<2>(d[i]);
    }
    cout << total;
    return 0;
}
