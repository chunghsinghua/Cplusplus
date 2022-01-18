#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N];
map<int, int> mp;

int color(int w, int n)
{
    vector<int> cnt(n, 0);
    int nc = 0;
    for (int i = 0; i < w; ++i)
    {
        int color = mp[d[i]];
        cnt[color]++;
        if (cnt[color] == 1)
            nc++;
    }
    int maxc = nc;
    for (int left = 0, i = w; i < n; ++i, ++left)
    {
        int color = mp[d[i]];
        cnt[color]++;
        if (cnt[color] == 1)
            nc++;
        color = mp[d[left]];
        cnt[color]--;
        if (cnt[color] == 0)
            nc--;
        maxc = max(maxc, nc);
    }
    return maxc;
}

int main()
{
    freopen("P_3_10_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    for (int i = 0; i < n; ++i)
        mp[d[i]] = 0;
    int ncolor = 0;
    for (auto &i : mp)
        i.second = ncolor++;
    int length = 0;
    for (int jump = n / 2; jump > 0; jump >>= 1)
    {
        while (color(length + jump, n) < ncolor)
            length += jump;
    }
    cout << length + 1;
    return 0;
}
