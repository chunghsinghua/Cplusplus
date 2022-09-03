#include <bits/stdc++.h>

using namespace std;

#define N 210
typedef long long ll;

ll d[N], ans = 0;
ll n, p = 10009;

void fun(int idx, ll prod)
{
    if (idx >= n)
    {
        if (prod == 1)
            ans++;
        return;
    }
    fun(idx + 1, prod * d[idx] % p);
    fun(idx + 1, prod);
}

int main()
{
    freopen("p_1_7_5.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    fun(0, 1);
    cout << ans - 1;
    return 0;
}
