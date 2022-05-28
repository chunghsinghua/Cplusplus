#include <bits/stdc++.h>

using namespace std;

#define N 200005
typedef long long ll;

int d[N];

int main()
{
    freopen("P_2_15_4.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    for (int i = 1; i < n; ++i)
        d[i] += d[i - 1];
    int key, room = 0;
    int total = d[n - 1];
    for (int i = 0; i < m; ++i)
    {
        cin >> key;
        if (room != 0)
            key += d[room - 1];
        if (key > total)
        {
            key -= total;
            room = 0;
        }
        if (d[room] >= key)
        {
            room = (room + 1) % n;
            continue;
        }

        for (int jump = (n - room) / 2; jump > 0; jump >>= 1)
            while (room + jump < n && d[room + jump] < key)
                room += jump;

        room = (room + 2) % n;
    }
    cout << room;
    return 0;
}
