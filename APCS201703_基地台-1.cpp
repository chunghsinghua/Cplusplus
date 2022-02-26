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
    freopen("P_4_9_5.in", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    sort(d, d + n);
    int len = 0;
    int mxlen = d[n - 1] - d[0];
    for (int jump = mxlen / 2; jump > 0; jump >>= 1)
    {
        while (len + jump < mxlen && !enough(len + jump))
            len += jump;
    }
    cout << len + 1;
    return 0;
}
