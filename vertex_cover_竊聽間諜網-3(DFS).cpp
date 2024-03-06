#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int t[N], deg[N], mark[N];
vector<int> adj[N];

int fun(int v)
{
    int num = 0;
    for (int e : adj[v])
    {
        num += fun(e);
    }
    if (mark[v] == 0)
        mark[t[v]] = 1;
    else if (mark[v])
        num++;
    return num;
}

int main()
{
    freopen("Q_8_10_4.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> t[i];
        adj[t[i]].push_back(i);
    }
    cout << fun(0);
    return 0;
}
