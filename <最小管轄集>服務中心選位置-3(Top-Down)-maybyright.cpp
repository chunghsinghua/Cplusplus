#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int mark[N], dom[N];
vector<int> adj[N];

// 0 is bound, 1 is dominating point, 2 is free;
void dfs(int v, int p)
{
    for (int e : adj[v])
        if (e != p)
            dfs(e, v);
    if (mark[v] == 0)
        mark[p] = 1;
    else if (mark[v] == 1)
    {
        dom[v] = 1;
        if (mark[p] != 1)
            mark[p] = 2;
    }
}
// int dp(int root, int n)
// {
//     dfs(root);
//     if (mark[root] == 1 || mark[root] == 0) // mark[v]!=2
//         dom[root] = 1;
//     int sum = 0;
//     for (int i = 1; i <= n; ++i)
//         sum += dom[i];
//     return sum;
// }

int main()
{
    freopen("Q_8_9_4.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += dom[i];
    cout << sum;
    return 0;
}
