#include <bits/stdc++.h>

using namespace std;

#define N 200005
typedef long long ll;

int d[N];

int main()
{
    freopen("P_2_15_1.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    int room = 0, key, sum = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> key;
        while (room < n && sum + d[room] < key)
        {
            sum += d[room];
            room++;
            if (room == n)
                room = 0;
        }

        room = (room + 1) % n;
        sum = 0;
    }
    cout << room;
    return 0;
}
