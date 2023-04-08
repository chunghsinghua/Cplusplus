#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int d[N], dp[N];

int main()
{
    freopen("P_6_2_3.in", "r", stdin);
    int n;
    cin >> n >> d[1] >> d[2];
    d[2] = max(d[1], d[2]);
    for (int i = 3; i <= n; ++i)
    {
        cin >> d[i];
        d[i] = max(d[i - 1], d[i] + d[i - 2]);
    }
    cout << d[n];
    return 0;
}
