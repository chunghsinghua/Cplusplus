#include <bits/stdc++.h>
using namespace std;

#define N 200010
typedef long long ll;

int d[N], dp[N];

int main()
{
    freopen("P_6_13_2.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    dp[0] = d[0];
    priority_queue<pair<int, int>> pq;
    pq.push({-dp[0], 0});
    for (int i = 0; i < n; ++i)
    {
        if (i <= k)
            dp[i] = d[i];
        else
        {
            while (pq.top().second < i - 2 * k - 1)
                pq.pop();
            dp[i] = d[i] + (-pq.top().first);
        }
        pq.push({-dp[i], i});
    }
    cout << *min_element(dp + n - k - 1, dp + n);
    return 0;
}
