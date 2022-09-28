#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;
vector<int> child[N];
int wei[N], h[N], step[N];
int longest = 0, maxstep = 0;

void dfs(int v)
{
    for (int e : child[v])
    {
        h[e] = h[v] + wei[e];
        longest = max(longest, h[e]);
        step[e] = step[v] + 1;
        maxstep = max(maxstep, step[e]);
        dfs(e);
    }
    return;
}

int main()
{
    freopen("P_8_2_5.in", "r", stdin);
    int n, p, w;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> p >> w;
        wei[i] = w;
        child[p].push_back(i);
    }

    dfs(0);
    cout << longest << "\n"
         << maxstep;

    return 0;
}
