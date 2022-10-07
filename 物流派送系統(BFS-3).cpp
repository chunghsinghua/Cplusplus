#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int d[N], wei[N], stop[N], total[N];
vector<int> adj[N];

int main()
{
    freopen("P_8_2_4.in", "r", stdin);
    int n, x, w;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> x >> w;
        adj[x].push_back(i);
        wei[i] = w;
    }
    int hop = 0, mx = 0;
    queue<int> que;
    que.push(0);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int a : adj[now])
        {
            stop[a] = stop[now] + 1;
            hop = max(hop, stop[a]);
            total[a] = total[now] + wei[a];
            mx = max(mx, total[a]);
            que.push(a);
        }
    }
    cout << mx << '\n'
         << hop;
    return 0;
}
