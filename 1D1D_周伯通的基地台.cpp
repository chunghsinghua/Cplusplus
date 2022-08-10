#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N], dp[N];

int main()
{
    freopen("P_6_13_3.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    deque<int> deq;
    deq.push_back(0);
    dp[0] = d[0];
    for (int i = 1; i < n; ++i)
    {
        if (i <= k)
            dp[i] = d[i];
        else
        {
            if (deq.front() <= i - 2 * k - 2) // question1
                deq.pop_front();
            dp[i] = d[i] + dp[deq.front()];
        }
        while (!deq.empty() && dp[deq.back()] >= dp[i])
            deq.pop_back();
        deq.push_back(i);
    }
    int ans = *min_element(dp + n - 1 - k, dp + n);
    cout << ans;
    return 0;
}
