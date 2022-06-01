#include <bits/stdc++.h>

using namespace std;

#define N 110
typedef long long ll;

int d[N];
int n, m, s;

vector<int> g[N];

pair<int, int> bfs(int s)
{
    bool visit[N] = {false};
    queue<int> q;
    q.push(s);
    visit[s] = true;
    int pnum = 0, sum = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int e : g[p])
        {
            if (!visit[e])
            {
                pnum++;
                q.push(e);
                visit[e] = true;
                d[e] = d[p] + 1;
                sum += d[e];
            }
        }
    }
    return {pnum, sum};
}

int main()
{
    freopen("P_7_1_1.in", "r", stdin);
    cin >> n >> m >> s;
    int from, to;
    for (int i = 0; i < m; ++i)
    {
        cin >> from >> to;
        g[from].push_back(to);
    }

    pair<int, int> res = bfs(s);
    cout << res.first << "\n"
         << res.second;

    return 0;
}
