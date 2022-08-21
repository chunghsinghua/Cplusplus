#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_2_11_3.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += d[j];
            if (sum <= k)
                ans = max(sum, ans);
        }
    }
    cout << ans;
    return 0;
}
