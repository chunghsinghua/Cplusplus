#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int d[N];

int main()
{
    freopen("P_6_1_4.in", "r", stdin);
    int n;
    cin >> n;
    int pp = 0, p = 0;
    int ans, t;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        ans = min(p, pp) + t;
        pp = p;
        p = ans;
    }
    cout << ans;
    return 0;
}
