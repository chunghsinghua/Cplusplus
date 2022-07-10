#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int c[N], cnt[N];

int main()
{
    freopen("Q_3_12_5.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    int ncolor = 0;
    for (int i = 0; i < n; ++i)
        mp[c[i]] = 0;

    for (auto &p : mp)
        p.second = ncolor++;

    int total = 0, wcolor = 0;
    for (int i = 0; i < m; ++i)
    {
        int color = mp[c[i]];
        cnt[color]++;
        if (cnt[color] == 1)
            wcolor++;
    }
    if (wcolor == m)
        total++;
    for (int left = 0, right = m; right < n; ++right, ++left)
    {
        int color = mp[c[right]];
        cnt[color]++;
        if (cnt[color] == 1)
            wcolor++;
        color = mp[c[left]];
        cnt[color]--;
        if (cnt[color] == 0)
            wcolor--;
        if (wcolor == m)
            total++;
    }
    cout << total;
    return 0;
}
