#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_6_15_5.in", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> p(n, vector<int>(3, 0));    // x, y, idx
    vector<vector<int>> adj(n, vector<int>(4, -1)); // neighbors
    vector<int> mirror(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i][0] >> p[i][1] >> mirror[i];
        p[i][2] = i;
    }
    sort(p.begin(), p.end());
    const int east = 0, south = 1, west = 2, north = 3;
    vector<vector<int>> direction(2, vector<int>(4)); // 0:/ ; 1:\;
    direction[1] = {south, east, north, west};
    direction[0] = {north, west, south, east};
    int px = -1, prev = -1, idx, x, y;
    for (auto e : p)
    {
        idx = e[2];
        x = e[0];
        if (x == px)
        {
            adj[idx][south] = prev;
            adj[prev][north] = idx;
        }
        px = x;
        prev = idx;
    }
    int py = -4000000, v = -1; // v is the first mirror
    sort(p.begin(), p.end(), [](vector<int> &x, vector<int> &y)
         { if(x[1]==y[1])
            return x[0] < y[0];
        return x[1] < y[1]; });
    for (auto e : p)
    {
        idx = e[2];
        y = e[1];
        if (y == py)
        {
            adj[idx][west] = prev;
            adj[prev][east] = idx;
        }
        py = y;
        prev = idx;
        if (v < 0 && y == 0)
            v = idx;
    }
    int cnt = 0, nextd = east;
    while (v >= 0)
    {
        cnt++;
        nextd = direction[mirror[v]][nextd];
        v = adj[v][nextd];
    }
    cout << cnt;

    return 0;
}
