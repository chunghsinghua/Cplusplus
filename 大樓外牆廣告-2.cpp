#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int d[N];

ll fun(int a[], int le, int ri)
{
    if (le >= ri)
        return 0;
    if (le + 1 == ri)
        return a[le];
    int m = (le + ri) >> 1;
    ll w = max(fun(a, le, m), fun(a, m + 1, ri));
    int i = m, j = m;
    ll height = d[m], mx = 0;
    while (i >= le || j < ri)
    {
        if (i < le)
            height = d[j];
        else if (j >= ri)
            height = d[i];
        else
            height = max(d[i], d[j]);

        while (i >= le && d[i] >= height)
            i--;
        while (j < ri && d[j] >= height)
            j++;
        mx = max(mx, height * (j - i - 1));
    }
    return mx;
}

int main()
{
    freopen("P_5_7_1.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    cout << fun(d, 0, n);

    return 0;
}
