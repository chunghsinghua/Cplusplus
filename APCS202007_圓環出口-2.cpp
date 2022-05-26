#include <bits/stdc++.h>

using namespace std;

#define N 400005
typedef long long ll;

int p[N], q[N];

int main()
{
    freopen("P_2_15_2.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 1; i < n; ++i)
        p[i] += p[i - 1];
    int room = 0;
    int total = p[n - 1];
    for (int i = 0; i < m; ++i)
    {
        int key;
        cin >> key;
        if (room != 0)
            key += p[room - 1];
        if (key > total)
        {
            key -= total;
            room = 0;
        }

        room = lower_bound(p + room, p + n, key) - p;
        room = (room + 1) % n;
    }
    cout << room;
    return 0;
}
