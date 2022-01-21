#include <bits/stdc++.h>
using namespace std;

#define N 200010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_3_8_5.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    multiset<int> mset;
    for (int i = 0; i < l; ++i)
        mset.insert(d[i]);
    int ans = *mset.rbegin() - *mset.begin();
    for (int i = l, left = 0; i < n; ++i, ++left)
    {
        mset.insert(d[i]);
        mset.erase(d[left]);
        ans = max(ans, *mset.rbegin() - *mset.begin());
    }
    cout << ans;
    return 0;
}
