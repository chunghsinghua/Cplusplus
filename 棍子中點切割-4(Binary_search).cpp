#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int a[N];
ll fun(int le, int ri)
{
    if (le + 1 >= ri)
        return 0;
    ll cost = a[ri] - a[le];
    int mid = (a[le] + a[ri]) / 2;
    int idx, lidx = le, ridx = ri;
    while (lidx <= ridx)
    {
        int midx = (lidx + ridx) / 2;
        if (a[midx] == mid)
        {
            idx = midx;
            break;
        }
        else if (a[midx] < mid)
            lidx = midx + 1;
        else
            ridx = midx - 1;
    }
    if (lidx > ridx)
        idx = lidx;
    if (a[idx - 1] - a[le] >= a[ri] - a[idx])
        idx--;
    return cost + fun(le, idx) + fun(idx, ri);
}
int main()
{
    freopen("p_1_3_1.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    a[0] = 0, a[n + 1] = l;
    cout << fun(0, n + 1);
    return 0;
}
