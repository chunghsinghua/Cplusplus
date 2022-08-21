#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_2_11_4.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    for (int i = 1; i <= n; ++i)
        d[i] += d[i - 1];
    int ans = -1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int t = d[j] - d[i];
            if (t <= k)
                ans = max(ans, t);
        }
    }
    cout << ans;
    return 0;
}
