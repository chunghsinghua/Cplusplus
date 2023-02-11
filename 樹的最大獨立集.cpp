#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int choose[N], parent[N];
vector<int> adj[N];

int dfs(int root)
{
    int num = 0;
    for (int e : adj[root])
    {
        num += dfs(e);
    }
    if (choose[root])
    {
        choose[parent[root]] = 0;
        return num + 1;
    }
    return num;
}

int main()
{
    freopen("P_8_8_1.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> parent[i];
        adj[parent[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        choose[i] = 1;
    parent[0] = n;
    cout << dfs(0);
    return 0;
}
