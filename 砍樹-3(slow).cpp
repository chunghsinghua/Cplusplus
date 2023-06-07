#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int c[N], h[N];

int main()
{
    freopen("P_3_6_4.in", "r", stdin);
    int n, l;
    int total = 0, mx = 0;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 1; i <= n; ++i)
        cin >> h[i];

    c[n + 1] = l;
    h[0] = h[n + 1] = 1e9;

    while (1)
    {
        int i;
        for (i = 1; i <= n; ++i)
        {
            if (h[i] == 0)
                continue;
            int pre = i - 1, next = i + 1;
            while (h[pre] == 0)
                pre--;
            while (h[next] == 0)
                next++;
            if (c[i] - h[i] >= c[pre] || c[i] + h[i] <= c[next])
                break;
        }

        if (i > n)
            break;

        total++;
        mx = max(mx, h[i]);
        h[i] = 0;
    }
    cout << total << "\n"
         << mx;
    return 0;
}
