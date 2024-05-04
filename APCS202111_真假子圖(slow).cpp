#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

vector<vector<int>> adj(N);

bool bfs(vector<vector<int>> &vec, vector<int> &col, int v)
{
    col[v] = 1;
    queue<int> que;
    que.push(v);
    while (!que.empty())
    {
        int p = que.front();
        que.pop();
        for (int e : vec[p])
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

bool bipar(vector<vector<int>> &vec, int n)
{
    vector<int> col(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (col[i] >= 0)
            continue;
        bool check = bfs(vec, col, i);
        if (!check)
            return false;
    }
    return true;
}

int main()
{
    // freopen("Q_8_16_5.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, p, k;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> p >> k;
    for (int i = 1; i <= p; ++i)
    {
        vector<vector<int>> temp(n);
        for (int ii = 0; ii < n; ++ii)
        {
            for (int e : adj[ii])
                temp[ii].push_back(e);
        }
        for (int j = 0; j < k; ++j)
        {
            cin >> a >> b;
            temp[a].push_back(b);
            temp[b].push_back(a);
        }
        if (!bipar(temp, n))
            cout << i << '\n';
    }
    return 0;
}
