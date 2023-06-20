#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

struct GAME
{
    int s, t, e;
} game[N];

bool cmp(GAME &a, GAME &b)
{
    return a.t < b.t;
}

int dp[N];

int main()
{
    freopen("P_6_16_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> game[i].s >> game[i].t >> game[i].e;
    sort(game, game + n + 1, cmp);
    map<int, int> mp;
    mp.insert({-1, 0});
    for (int i = 1; i <= n; ++i)
    {
        auto it = mp.lower_bound(game[i].s);
        dp[i] = max(dp[i - 1], game[i].e + prev(it)->second);
        mp[game[i].t] = max(mp[game[i].t], dp[i]);
    }
    cout << dp[n];
    return 0;
}
