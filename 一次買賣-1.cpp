#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_4_12_1.in", "r", stdin);
    int n;
    cin >> n;
    int mn = 1e9 + 1;
    int ans = 0;
    int t;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        ans = max(ans, t - mn);
        mn = min(mn, t);
    }

    cout << ans;

    return 0;
}
