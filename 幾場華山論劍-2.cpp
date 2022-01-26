#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int main()
{
    freopen("P_4_4_1.in", "r", stdin);
    vector<pair<int, int>> d;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int s, t;
        cin >> s >> t;
        d.push_back({t, s});
    }
    int tend = -1, total = 0;
    sort(d.begin(), d.end());
    for (int i = 0; i < n; ++i)
    {
        if (d[i].second > tend)
        {
            total++;
            tend = d[i].first;
        }
    }
    cout << total;
    return 0;
}
