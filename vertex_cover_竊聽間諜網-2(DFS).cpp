#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

vector<int> adj[N];
int mark[N], p[N];

int dfs(int root)
{
    int num = 0;
    for (int e : adj[root])
        num += dfs(e);
    if (mark[root])
    {
        num++;
        mark[p[root]] = 0;
    }
    return num;
}

int main()
{
    freopen("Q_8_10_3.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        mark[i] = 1;
    mark[0] = n;    //dummy
    cout << n - dfs(0);
    return 0;
}
