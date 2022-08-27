#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int d[N], group[N];

int main()
{
    // freopen("p_1_1_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    memset(group, -1, sizeof(group));
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (group[i] >= 0)
            continue;
        group[i] = i;
        ans++;
        int now = i;
        while (d[now] != i)
        {
            group[d[now]] = i;
            now = d[now];
        }
    }
    cout << ans;
    return 0;
}
