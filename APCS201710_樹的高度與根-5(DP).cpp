#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int parent[N], height[N];
vector<int> child[N];

int findh(int v)
{
    if (height[v] >= 0)
        return height[v];
    height[v] = 0;
    for (int e : child[v])
    {
        height[v] = max(height[v], findh(e) + 1);
    }
    return height[v];
}

int main()
{
    freopen("P_3_1_4.in", "r", stdin);
    int n, t, cnum;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> cnum;
        for (int j = 0; j < cnum; ++j)
        {
            cin >> t;
            child[i].push_back(t);
            parent[t] = i;
        }
    }
    int root;
    for (root = 1; root < n; ++root)
        if (parent[root] == 0)
            break;
    memset(height, -1, sizeof(height));
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += findh(i);
    cout << root << "\n"
         << sum;

    return 0;
}
