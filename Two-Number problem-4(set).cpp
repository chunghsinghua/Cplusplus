#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int a[N];

int main()
{
    freopen("P_2_6_4.in", "r", stdin);
    int m, n, k, t;
    cin >> m >> n >> k;
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    set<int> b;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        b.insert(t);
    }
    int cnt = 0;
    for (int i = 0; i < m; ++i)
        if (b.count(k - a[i]))
            cnt++;
    cout << cnt;
    return 0;
}
