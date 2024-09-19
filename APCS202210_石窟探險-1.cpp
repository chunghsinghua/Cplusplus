#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

vector<vector<int>> tree(100000, vector<int>());

void fun(int p)
{
    int child = 2 + (p % 2);
    for (int i = 0; i < child; ++i)
    {
        int t;
        cin >> t;
        if (t == 0)
            continue;
        tree[p].push_back(t);
        fun(t);
    }
}

ll fun2(int v)
{
    ll ret = 0;
    for (int e : tree[v])
    {
        ret += abs(v - e);
        ret += fun2(e);
    }
    return ret;
}

int main()
{
    int v;
    cin >> v;
    fun(v);
    cout << fun2(v);
    return 0;
}
