#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int a[N], psum[N];

int main()
{
    freopen("P_2_11_4.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        psum[i] = psum[i - 1] + a[i];
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int t = psum[j] - psum[i];
            if (t <= k)
                ans = max(ans, t);
        }
    }
    cout << ans;
    return 0;
}
