#include <bits/stdc++.h>

using namespace std;

#define N 30
typedef long long ll;

int u[N], f[N], r[N], o[7] = {0, 6, 5, 4, 3, 2, 1};

int main()
{
    // freopen("P_6_19_5.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        u[i] = 1, f[i] = 4, r[i] = 2;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (b == -1)
        {
            int up = o[f[a]];
            f[a] = u[a];
            u[a] = up;
        }
        else if (b == -2)
        {
            int up = o[r[a]];
            r[a] = u[a];
            u[a] = up;
        }
        else
        {
            swap(r[a], r[b]);
            swap(u[a], u[b]);
            swap(f[a], f[b]);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << u[i] << ' ';
    return 0;
}
