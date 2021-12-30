#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N];
multiset<int> mset;

int main()
{
    freopen("P_3_8_3.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    for (int i = 0; i < l; ++i)
        mset.insert(d[i]);
    int ans = *mset.rbegin() - *mset.begin();
    for (int i = l; i < n; ++i)
    {
        auto it = mset.find(d[i - l]);
        mset.erase(it);
        mset.insert(d[i]);
        ans = max(ans, *mset.rbegin() - *mset.begin());
    }
    cout << ans;
    return 0;
}
