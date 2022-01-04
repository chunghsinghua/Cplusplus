#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N], cnt[N];

int main()
{
    freopen("P_3_9_5.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    int ncolor = 0;
    for (int i = 0; i < l; ++i)
    {
        int color = d[i];
        cnt[color]++;
        if (cnt[color] == 1)
            ncolor++;
    }
    int ans = ncolor;
    for (int i = l, left = 0; i < n; ++i, ++left)
    {
        int color = d[i];
        cnt[color]++;
        if (cnt[color] == 1)
            ncolor++;
        color = d[left];
        cnt[color]--;
        if (cnt[color] == 0)
            ncolor--;
        ans = max(ans, ncolor);
    }
    cout << ans;
    return 0;
}
