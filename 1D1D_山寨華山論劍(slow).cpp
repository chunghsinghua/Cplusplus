#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

struct SEG
{
    int l, r, w;
} seg[N];

int dp[N];

int main()
{
    freopen("P_6_16_4.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> seg[i].l >> seg[i].r >> seg[i].w;
    dp[0] = 0;
    seg[0].r = -1;
    sort(seg, seg + n + 1, [](SEG &a, SEG &b)
         { return a.r < b.r; });
    for (int i = 1; i <= n; ++i)
    {
        int it = i - 1;
        while (it >= 0 && seg[it].r >= seg[i].l)
            it--;
        dp[i] = dp[it] + seg[i].w;
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[n];

    return 0;
}
