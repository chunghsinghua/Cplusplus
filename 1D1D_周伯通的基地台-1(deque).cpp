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
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    deque<int> deq;

    for (int i = 0; i < n; ++i)
    {
        if (i <= k)
            dp[i] = c[i];
        else
        {
            if (deq.front() < i - 2 * k - 1)
                deq.pop_front();
            dp[i] = c[i] + dp[deq.front()];
        }
        while (!deq.empty() && dp[deq.back()] >= dp[i])
            deq.pop_back();
        deq.push_back(i);
    }
    cout << *min_element(dp + n - 1 - k, dp + n);

    return 0;
}
