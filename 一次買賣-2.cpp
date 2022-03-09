#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_4_12_4.in", "r", stdin);
    int n;
    cin >> n;
    multiset<int> mset;
    int t;
    cin >> t;
    mset.insert(t);
    int ans = 0;
    for (int i = 1; i < n; ++i)
    {
        cin >> t;
        ans = max(ans, t - *mset.begin());
        mset.insert(t);
    }

    cout << ans;

    return 0;
}
