#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int p[N], chosen[N];
vector<int> adj[N];

int dfs(int n)
{
    int num = 0;
    for (int e : adj[n])
        num += dfs(e);
    if (chosen[n])
    {
        num += 1;
        chosen[p[n]] = 0;
    }
    return num;
}

int main()
{
    freopen("P_8_8_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        chosen[i] = 1;
    p[0] = n;
    cout << dfs(0);
    return 0;
}
