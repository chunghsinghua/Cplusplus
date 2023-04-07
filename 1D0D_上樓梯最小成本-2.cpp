#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_6_1_4.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    for (int i = 3; i <= n; ++i)
        d[i] += min(d[i - 1], d[i - 2]);
    cout << d[n];
    return 0;
}
