#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_6_7_5.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i].second;
    for (int i = 0; i < n; ++i)
        cin >> vec[i].first;
    sort(vec.begin(), vec.end());
    multiset<int> mset;
    for (int i = 0; i < k; ++i)
        mset.insert(-1);
    int cnt = 0;
    for (auto e : vec)
    {
        auto it = mset.lower_bound(e.second); // e.left
        if (it == mset.begin())
            continue;
        it--;
        mset.erase(it);
        mset.insert(e.first); // e.right
        cnt++;
    }
    cout << cnt;
    return 0;
}
