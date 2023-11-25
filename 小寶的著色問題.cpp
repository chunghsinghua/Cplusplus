#include <bits/stdc++.h>

using namespace std;

#define N 10010
typedef long long ll;

int col[N];
vector<int> adj[N];

bool bfs(int p)
{
    col[p] = 1;
    queue<int> que;
    que.push(p);
    while (!que.empty())
    {
        int p = que.front();
        que.pop();
        for (int e : adj[p])
        {
            if (col[e] < 0)
            {
                col[e] = col[p] ^ 1;
                que.push(e);
            }
            else if (col[e] == col[p])
                return false;
        }
    }
    return true;
}

int main()
{
    freopen("Q_7_8_2.in", "r", stdin);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        bool check = true;
        for (int i = 0; i < n; ++i)
            adj[i].clear();
        for (int i = 0; i < m; ++i)
        {
            int s, t;
            cin >> s >> t;
            adj[s].push_back(t);
            adj[t].push_back(s);
        }
        memset(col, -1, sizeof(col));

        for (int i = 0; i < n; ++i)
        {
            if (col[i] >= 0)
                continue;
            check = bfs(i);
            if (!check)
                break;
        }
        if (check)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
