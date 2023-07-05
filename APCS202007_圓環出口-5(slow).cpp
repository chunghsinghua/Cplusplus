#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int p[N];
int main()
{
    freopen("P_2_15_5.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    int room = 0, v;
    while (m--)
    {
        cin >> v;
        int sum = 0;
        while (room < n && sum + p[room] < v)
        {
            sum += p[room++];
            if (room == n)
                room = 0;
        }
        room = (room + 1) % n;
    }
    cout << room;
    return 0;
}
