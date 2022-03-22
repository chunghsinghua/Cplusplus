#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int d[N];
struct answer
{
    int mn, mx;
};
answer fun(int a[], int s, int t)
{
    if (s + 1 >= t)
        return {a[s], a[s]};
    int m = (s + t) >> 1;
    answer le = fun(a, s, m), ri = fun(a, m, t);
    return {min(le.mn, ri.mn), max(le.mx, ri.mx)};
}

int main()
{
    // freopen("P_4_9_2.in", "r", stdin);
    srand(time(0));
    int n = 10;
    for (int i = 0; i < n; ++i)
        d[i] = rand() % 100;

    for (int i = 0; i < n; ++i)
        cout << d[i] << " ";
    cout << "\n";
    answer ans = fun(d, 0, n);
    cout << ans.mn << "\n"
         << ans.mx;

    return 0;
}
