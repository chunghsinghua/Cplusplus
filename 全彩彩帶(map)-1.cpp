#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N], cnt[N];

int main()
{
    freopen("P_3_10_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    map<int, int> ref;
    for (int i = 0; i < n; ++i)
        ref[d[i]] = 0;
    int index = 0;
    for (auto it = ref.begin(); it != ref.end(); ++it)
        it->second = index++;
    int totalcolor = index;
    int wcolor = 0;
    int ans = 300000;
    for (int i = 0, left = 0; i < n; ++i)
    {
        int color = ref[d[i]];
        cnt[color]++;
        if (cnt[color] == 1)
            wcolor++;
        while (1)
        {
            color = ref[d[left]];
            if (cnt[color] == 1)
                break;
            cnt[color]--;
            left++;
        }
        if (wcolor == totalcolor)
            ans = min(ans, i - left + 1);
    }
    cout << ans;
    return 0;
}
