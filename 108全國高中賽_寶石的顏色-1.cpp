#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;
int c[N], counter[N], ans;
vector<int> adj[N];
map<int, int> refe;

void dfs(int root)
{
    int cc = refe[c[root]];
    counter[cc]++;
    ans = max(ans, counter[cc]);
    for (int e : adj[root])
        dfs(e);
    counter[cc]--;
}

int main()
{
    freopen("P_8_7_1.in", "r", stdin);
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
    dfs(0);
    cout << ans;
    return 0;
}
