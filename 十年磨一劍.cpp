#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_4_3_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    ll psum = 0, total = 0;
    sort(d, d + n);
    for (int i = 0; i < n; ++i)
    {
        psum += d[i];
        total += psum;
    }
    cout << total;
    return 0;
}
