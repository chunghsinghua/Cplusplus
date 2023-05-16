#include <bits/stdc++.h>
using namespace std;

#define N 200010
typedef long long ll;

int c[N], dp[N];

int main()
{
    freopen("P_6_13_2.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; ++i)
    {
        while (!pq.empty() && pq.top().second < i - k * 2 - 1)
            pq.pop();

        if (i <= k + 1)
            dp[i] = c[i];
        else
            dp[i] = c[i] + (-pq.top().first);

        pq.push({-dp[i], i});
    }

    cout << *min_element(dp + n - k, dp + n + 1);

    return 0;
}
