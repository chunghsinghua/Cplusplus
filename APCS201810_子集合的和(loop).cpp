#include <bits/stdc++.h>

using namespace std;

#define N 210
typedef long long ll;

int d[N];

int main()
{
    freopen("q_1_8_4.in", "r", stdin);
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    int ans = 0;
    for (int i = 1; i < (1 << n); ++i)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
                sum += d[j];
        }
        if (sum <= p)
            ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}
