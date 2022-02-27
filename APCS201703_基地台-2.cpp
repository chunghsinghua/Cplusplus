#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int d[N], n, k;

bool enough(int r)
{
    int nseg = k;
    int endline = -1;
    for (int i = 0; i < n; ++i)
    {
        if (d[i] <= endline)
            continue;
        if (nseg == 0)
            return false;
        endline = d[i] + r;
        nseg--;
    }
    return true;
}

int main()
{
    freopen("P_4_9_3.in", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    sort(d, d + n);
    int low = 1, up = d[n - 1] - d[0];
    while (low < up)
    {
        int t = (low + up) >> 1;
        if (!enough(t))
            low += 1;
        else
            up = t;
    }
    cout << low;

    return 0;
}
