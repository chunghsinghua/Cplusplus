#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int h[N];
vector<int> adj[N];

void dfs(int n, int p)
{
    for (int e : adj[n])
    {
        if (e != p)
        {
            h[e] = h[n] + 1;
            dfs(e, n);
        }
    }
}

int main()
{
    freopen("P_8_14_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    int mx = 0, idx;
    for (int i = 0; i < n; ++i)
    {
        if (h[i] > mx)
        {
            mx = h[i];
            idx = i;
        }
    }
    mx = 0;
    fill(h, h + n, 0);
    dfs(idx, -1);
    for (int i = 0; i < n; ++i)
        mx = max(mx, h[i]);

    cout << mx;

    return 0;
}
