#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int d[N];

ll fun(int a[], int le, int ri)
{
    if (le + 1 >= ri)
        return 0;
    int m = (le + ri) >> 1;
    ll w = fun(a, le, m) + fun(a, m, ri);
    ll cross = 0;
    int j = m;
    for (int i = le; i < m; ++i)
    {
        while (j < ri && a[j] < a[i])
            j++;
        cross += j - m;
    }
    sort(a + le, a + ri);

    return w + cross;
}

int main()
{
    freopen("P_5_4_2.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    cout << fun(d, 0, n);
    return 0;
}
