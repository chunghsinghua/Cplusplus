#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int fun(int n, int m, int k)
{
    if (k == 0)
        return 0;
    return (fun(n - 1, m, k - 1) + m) % n;
}
int main()
{
    // freopen("Q_7_11_5.in", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    cout << fun(n, m, k) + 1;
    return 0;
}
