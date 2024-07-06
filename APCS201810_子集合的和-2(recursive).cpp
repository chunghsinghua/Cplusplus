#include <bits/stdc++.h>

using namespace std;

#define N 210
typedef long long ll;

int d[N], ans = 0;
int n, p;

void fun(int idx, int sum)
{
    if (idx >= n)
    {
        if (sum <= p)
        {
            ans = max(ans, sum);
        }
        return;
    }
    fun(idx + 1, sum + d[idx]);
    fun(idx + 1, sum);
}

int main()
{
    freopen("q_1_8_3.in", "r", stdin);
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    fun(0, 0);
    cout << ans;
    return 0;
}
