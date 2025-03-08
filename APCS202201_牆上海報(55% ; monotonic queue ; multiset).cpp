#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_5_4_1.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> h(n), w(k);
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    for (int i = 0; i < k; ++i)
        cin >> w[i];
    multiset<int> mset;
    for (int i = 0; i < w[0]; ++i)
        mset.insert(h[i]);
    int mx = *mset.begin();
    for (int le = 0, ri = w[0]; ri < n; ++le, ++ri)
    {
        mset.erase(h[le]);
        mset.insert(h[ri]);
        mx = max(mx, *mset.begin());
    }
    cout << mx;
    return 0;
}
