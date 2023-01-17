#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int parent[N], height[N];
vector<int> child[N];

void findh(int v)
{
    height[v] = 0;
    for (int e : child[v])
    {
        findh(e);
        height[v] = max(height[v], height[e] + 1);
    }
}

int main()
{
    freopen("P_3_1_3.in", "r", stdin);
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
    findh(root);
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += height[i];
    cout << root << "\n"
         << sum;
}
