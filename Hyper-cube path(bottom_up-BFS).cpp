#include <bits/stdc++.h>

using namespace std;

#define N 10000010
typedef long long ll;

int d[N], dp[N];
bool visit[N];

int main()
{
    freopen("P_6_20_3.in", "r", stdin);
    int n;
    cin >> n;
    int m = 1 << n;
    for (int i = 0; i < m; ++i)
        cin >> d[i];
    queue<int> que;
    que.push(0);
    visit[0] = true;

    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        dp[v] += d[v];
        for (int i = 0; i < n; ++i)
        {
            int bit = (1 << i);
            if ((v & bit) == 0)
            {
                int u = v | bit;
                dp[u] = max(dp[u], dp[v]);
                if (!visit[u])
                {
                    visit[u] = true;
                    que.push(u);
                }
            }
        }
    }
    cout << dp[m - 1];
    return 0;
}
