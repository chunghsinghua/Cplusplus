#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int parent[N], height[N], child[N];

int main()
{
    freopen("P_3_1_5.in", "r", stdin);
    int n, t;
    cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> child[i];
        if (child[i] == 0)
            q.push(i);
        for (int j = 0; j < child[i]; ++j)
        {
            cin >> t;
            parent[t] = i;
        }
    }
    int root;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        int p = parent[now];
        if (p == 0)
        {
            root = now;
            break;
        }
        height[p] = max(height[p], height[now] + 1);
        child[p]--;
        if (child[p] == 0)
            q.push(p);
    }
    cout << root << "\n";
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += height[i];
    cout << sum;
    return 0;
}
