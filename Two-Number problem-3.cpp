#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int a[N], b[N];

int main()
{
    freopen("P_2_6_5.in", "r", stdin);
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int j = n - 1, ans = 0;
    sort(a, a + m), sort(b, b + n);
    for (int i = 0; i < m; ++i)
    {
        while (j >= 0 && a[i] + b[j] > k)
            j--;
        if (j >= 0 && a[i] + b[j] == k)
            ans++;
    }
    cout << ans;
    return 0;
}
