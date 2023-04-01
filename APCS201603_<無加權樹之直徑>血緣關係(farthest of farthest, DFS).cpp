#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;
vector<int> adj[N];
int h[N];

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
    freopen("P_8_14_1.in", "r", stdin);
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
    int a = distance(h, max_element(h, h + n));
    fill(h, h + n, 0);
    dfs(a, -1);
    cout << *max_element(h, h + n);

    return 0;
}
