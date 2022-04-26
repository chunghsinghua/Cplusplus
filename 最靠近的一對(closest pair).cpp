#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

struct point
{
    ll x, y;
} a[N];

bool cmpx(point &s, point &t)
{
    return s.x < t.x;
}
bool cmpy(point &s, point &t)
{
    return s.y < t.y;
}

ll fun(point a[], int le, int ri)
{
    if (le + 1 >= ri)
        return 4e8;
    int m = (le + ri) >> 1;
    ll w = min(fun(a, le, m), fun(a, m, ri));
    int cnt = 0;
    point t[ri - le];
    for (int i = le; i < m; ++i)
        if (a[m].x - a[i].x < w)
            t[cnt++] = a[i];
    for (int i = m; i < ri; ++i)
        if (a[i].x - a[m].x < w)
            t[cnt++] = a[i];
    sort(t, t + cnt, cmpy);
    for (int i = 0; i < cnt - 1; ++i)
    {
        for (int j = i + 1; j < cnt; ++j)
        {
            if (t[j].y - t[i].y < w)
                w = min(w, abs(t[i].x - t[j].x) + abs(t[i].y - t[j].y));
        }
    }

    return w;
}

int main()
{
    freopen("P_4_15_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;
    sort(a, a + n, cmpx);
    cout << fun(a, 0, n);
    return 0;
}
