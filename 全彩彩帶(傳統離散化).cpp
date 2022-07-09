#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int c[N], refer[N], cnt[N];

int main()
{
    freopen("P_3_10_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    copy(begin(c), begin(c) + n, refer);
    sort(refer, refer + n);
    int ncolor = 1;
    for (int i = 1; i < n; ++i)
    {
        if (refer[i] != refer[i - 1])
        {
            refer[ncolor] = refer[i];
            ncolor++;
        }
    }
    for (int i = 0; i < n; ++i)
        c[i] = distance(refer, lower_bound(refer, refer + ncolor, c[i]));

    int ans = n, wcolor = 0;
    for (int left = 0, right = 0; right < n; ++right)
    {
        int color = c[right];
        cnt[color]++;
        if (cnt[color] == 1)
            wcolor++;
        while (1)
        {
            color = c[left];
            if (cnt[color] == 1)
                break;
            cnt[color]--;
            ++left;
        }
        if (wcolor == ncolor)
            ans = min(ans, right - left + 1);
    }
    cout << ans;
    return 0;
}
