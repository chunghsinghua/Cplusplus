#include <bits/stdc++.h>

using namespace std;

#define N 400005
typedef long long ll;

int p[N], q[N];

int main()
{
    freopen("P_2_15_5.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = n; i < 2 * n; ++i)
        p[i] = p[i - n];
    for (int i = 0; i < m; ++i)
        cin >> q[i];
    int idx = 0, room;
    for (int i = 0; i < m; ++i)
    {
        int key = q[i];
        int temp = 0;
        while (temp < key)
            temp += p[idx++];
        if (idx >= n)
            idx -= n;
    }
    cout << idx;
    return 0;
}
