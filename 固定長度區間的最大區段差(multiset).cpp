#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_3_8_3.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    multiset<int> mset;
    for (int i = 0; i < l; ++i)
        mset.insert(d[i]);

    int mx = *mset.rbegin() - *mset.begin();
    for (int left = 0, right = l; right < n; ++right, ++left)
    {
        mset.erase(d[left]);
        mset.insert(d[right]);
        mx = max(mx, *mset.rbegin() - *mset.begin());
    }
    cout << mx;
    return 0;
}
