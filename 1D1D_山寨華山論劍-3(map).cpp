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
    freopen("P_6_16_3.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> seg[i].l >> seg[i].r >> seg[i].w;
    sort(seg, seg + n + 1, [](SEG &a, SEG &b)
         { return a.r < b.r; });
    map<int, int> mp; //{seg.r; dp[i]}
    mp.insert({-1, dp[0] = 0});
    for (int i = 1; i <= n; ++i)
    {
        auto it = mp.lower_bound(seg[i].l);
        it--;
        dp[i] = max(dp[i - 1], seg[i].w + (it->second));
        mp[seg[i].r] = max(mp[seg[i].r], dp[i]);
    }
    cout << dp[n];
    return 0;
}
