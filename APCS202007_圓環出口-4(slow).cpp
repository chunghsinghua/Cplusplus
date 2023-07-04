#include <bits/stdc++.h>

using namespace std;

#define N 400010
typedef long long ll;

int p[N];
int main()
{
    freopen("P_2_15_3.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < n; ++i)
        p[n + i] = p[i];
    int room = 0, v;
    while (m--)
    {
        cin >> v;
        int sum = 0;
        while (sum < v)
            sum += p[room++];
        if (room >= n)
            room -= n;
    }
    cout << room;
    return 0;
}
