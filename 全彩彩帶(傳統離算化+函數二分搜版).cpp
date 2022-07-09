#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int c[N], refer[N];

int fun(int w, int n)
{
    vector<int> cnt(n, 0);
    int mx = 0, ncolor = 0;
    for (int i = 0; i < w; ++i)
    {
        int color = c[i];
        cnt[color]++;
        if (cnt[color] == 1)
            ncolor++;
    }
    mx = ncolor;
    for (int left = 0, right = w; right < n; ++right, ++left)
    {
        int color = c[right];
        cnt[color]++;
        if (cnt[color] == 1)
            ncolor++;
        color = c[left];
        cnt[color]--;
        if (cnt[color] == 0)
            ncolor--;
        mx = max(mx, ncolor);
    }
    return mx;
}

int main()
{
    freopen("P_3_10_2.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    copy(c, c + n, refer);
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

    int len = 1;
    for (int jump = n / 2; jump > 0; jump >>= 1)
        while (fun(len + jump, n) < ncolor)
            len += jump;

    cout << len + 1;

    return 0;
}
