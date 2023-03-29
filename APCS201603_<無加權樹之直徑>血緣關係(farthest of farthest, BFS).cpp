#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int h[N];
vector<int> adj[N];

void bfs(int n)
{
    memset(h, -1, sizeof(h));
    queue<int> que;
    que.push(n);
    h[n] = 0;
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (int e : adj[v])
        {
            if (h[e] >= 0)
                continue;
            h[e] = h[v] + 1;
            que.push(e);
        }
    }
}

int main()
{
    freopen("P_8_14_3.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(0);
    int a = distance(h, max_element(h, h + n));
    bfs(a);
    cout << *max_element(h, h + n);
    return 0;
}
