#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int d[N], dp0[N], dp1[N];

int main()
{
    freopen("P_6_3_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    dp0[0] = 2e4, dp0[1] = d[0];
    dp1[0] = d[0], dp1[1] = d[1];
    for (int i = 2; i < n; ++i)
    {
        dp0[i] = dp1[i - 1];
        dp1[i] = d[i] + min({dp1[i - 1], dp1[i - 2], dp0[i - 2]});
    }

    cout << min(dp0[n - 1], dp1[n - 1]);

    return 0;
}
