#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;
int c[N];
vector<int> adj[N];
map<int, int> refe;

int dfs(int root, int col)
{
    int nc = 0;
    for (int e : adj[root])
        nc = max(nc, dfs(e, col));
    return nc + (col == c[root]);
}

int main()
{
    freopen("P_8_7_2.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
        refe.insert({c[i], 0});
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }
    int cnt = 0;
    for (auto &e : refe)
        e.second = cnt++;
    for (int i = 0; i < n; ++i)
        c[i] = refe.find(c[i])->second;
    int mx = 0;
    for (auto e : refe)
        mx = max(mx, dfs(0, e.second));
    cout << mx;
    return 0;
}
