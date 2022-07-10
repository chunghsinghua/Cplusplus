#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int c[N], cnt[N];

int main()
{
    freopen("Q_3_11_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    int mx = 0;
    for (int left = 0, right = 0; right < n; ++right)
    {
        int color = c[right];
        cnt[color]++;
        while (cnt[color] > 1)
        {
            cnt[c[left]]--;
            left++;
        }
        mx = max(mx, right - left + 1);
    }
    cout << mx;
    return 0;
}
