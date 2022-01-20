#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N], cnt[N];

int main()
{
    freopen("Q_3_11_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    int ans = 0, ncolor = 0;
    for (int left = 0, right = 0; right < n; ++right)
    {
        int color = d[right];
        cnt[color]++;
        while (cnt[color] > 1 && left < right)
        {
            cnt[d[left]]--;
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    cout << ans;
    return 0;
}
