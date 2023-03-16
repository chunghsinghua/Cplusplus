#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int f1[N], f0[N], r[N];
vector<int> adj[N];

void dfs(int n)
{
    f0[n] = 0;
    f1[n] = r[n];
    for (int e : adj[n])
    {
        dfs(e);
        f1[n] += f0[e];
        f0[n] += max(f0[e], f1[e]);
    }
    return;
}

int main()
{
    freopen("P_8_11_4.in", "r", stdin);
    int n;
    cin >> n >> r[1];
    for (int i = 2; i <= n; ++i)
    {
        int p;
        cin >> p >> r[i];
        adj[p].push_back(i);
    }
    dfs(1);
    cout << max(f1[1], f0[1]);
    return 0;
}
