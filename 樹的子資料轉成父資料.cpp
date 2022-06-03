#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int parent[N];
vector<int> child[N];

void c2p(int n)
{
    memset(parent, -1, sizeof(parent)); // initial

    for (int i = 0; i < n; ++i)
    {
        for (int e : child[i])
            parent[e] = i;
    }
    return;
}

int main()
{
    // freopen("P_7_2_5.in", "r", stdin);
    int n; // edge
    cin >> n;
    int p, ch;

    for (int i = 0; i < n; ++i)
    {
        cin >> p >> ch;
        child[p].push_back(ch);
    }

    c2p(n + 1);
    for (int i = 0; i < n + 1; ++i)
        cout << i << " " << parent[i] << "\n";

    return 0;
}
