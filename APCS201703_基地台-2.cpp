#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int d[N];
int n, k;

bool enough(int r)
{
    int nseg = k, endline = -1;
    for (int i = 0; i < n; ++i)
    {
        if (d[i] <= endline)
            continue;
        if (nseg <= 0)
            return false;
        nseg--;
        endline = d[i] + r;
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
    int left = 1, right = d[n - 1] - d[0];
    while (left < right)
    {
        int m = (right + left) >> 1;
        if (!enough(m))
            left = m + 1;
        else
            right = m;
    }
    cout << left;
    return 0;
}
