#include <bits/stdc++.h>

using namespace std;

#define N 400010
typedef long long ll;

ll d[N];

int main()
{
    freopen("P_4_7_3.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    sort(d, d + n);
    int left = 0, right = n - 1;
    ll ans = 0, t;
    for (; n > 1; n--)
    {
        t = d[left] + d[left + 1];
        ans += t;
        left += 2;
        int j = right;
        while (j >= left && d[j] > t)
        {
            d[j + 1] = d[j];
            j--;
        }
        d[j + 1] = t;
        right++;
    }
    cout << d[left] << "\n"
         << ans;
    return 0;
}
