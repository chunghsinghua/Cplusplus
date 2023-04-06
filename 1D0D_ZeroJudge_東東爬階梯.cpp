#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

ll d[N];
ll fun(int n)
{
    if (d[n] > 0)
        return d[n];
    return d[n] = fun(n - 1) + fun(n - 2);
}

int main()
{
    // freopen("P_8_14_1.in", "r", stdin);
    int n;
    d[1] = 1, d[2] = 2;
    while (cin >> n)
        cout << fun(n) << '\n';
    return 0;
}
