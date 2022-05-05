#include <bits/stdc++.h>

using namespace std;

#define N 10005
typedef long long ll;

int d[N];

int fun(int m, int n)
{
    if (m == 1 || n == 1)
        return 1;
    return fun(m - 1, n) + fun(m, n - 1);
}

int main()
{
    // freopen("P_5_7_2.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    cout << fun(m, n);
    return 0;
}
