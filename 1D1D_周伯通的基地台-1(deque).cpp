#include <bits/stdc++.h>
using namespace std;

#define N 200010
typedef long long ll;

int c[N], dp[N];

int main()
{
    freopen("P_6_13_5.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    deque<int> deq;
    deq.push_back(1);
    dp[1] = c[1];
    for (int i = 2; i <= n; ++i)
    {
        if (deq.front() < i - (2 * k + 1))
            deq.pop_front();
        if (i <= k + 1)
            dp[i] = c[i];
        else
            dp[i] = c[i] + dp[deq.front()];

        while (!deq.empty() && dp[i] <= dp[deq.back()])
            deq.pop_back();
        deq.push_back(i);
    }
    cout << *min_element(dp + n - k, dp + n + 1);

    return 0;
}
