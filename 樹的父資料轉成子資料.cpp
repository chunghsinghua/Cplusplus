#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int parent[N];
vector<int> child[N];

void p2c(int n)
{
    for (int i = 0; i < n; ++i)
        child[i].clear();
    for (int i = 0; i < n; ++i)
        child[parent[i]].push_back(i);
}

int main()
{
    // freopen("P_7_2_5.in", "r", stdin);
    int n;
    cin >> n;
    int t;

    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        parent[i] = t;
    }

    p2c(n);
    for (int i = 0; i < n; ++i)
    {
        for (int e : child[i])
            cout << e << " ";

        cout << "\n";
    }

    return 0;
}
