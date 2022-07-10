#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N], cnt[N];

int main()
{
    freopen("Q_3_12_1.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        cin >> d[i];
        mp[d[i]] = 0;
    }
    int idx = 0;
    for (auto &i : mp)
        i.second = idx++;

    for (int i = 0; i < n; ++i)
        d[i] = mp[d[i]];

    int ncolor = 0, ans = 0;
    for (int i = 0; i < m; ++i)
    {
        int color = d[i];
        cnt[color]++;
        if (cnt[color] == 1)
            ncolor++;
    }
    if (ncolor == m)
        ans++;
    for (int i = m, left = 0; i < n; ++i, ++left)
    {
        int color = d[i];
        cnt[color]++;
        if (cnt[color] == 1)
            ncolor++;
        color = d[left];
        cnt[color]--;
        if (cnt[color] == 0)
            ncolor--;
        if (ncolor == m)
            ans++;
    }
    cout << ans;
    return 0;
}
