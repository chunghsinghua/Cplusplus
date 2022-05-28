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
    int room = 0, key;
    for (int i = 0; i < m; ++i)
    {
        cin >> key;
        while (key > 0)
        {
            key -= d[room++];
            if (room == n)
                room = 0;
        }
    }
    cout << room;
    return 0;
}
