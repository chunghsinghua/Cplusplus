#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

pair<int, int> d[N];

int main()
{
    freopen("P_4_14_2.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i].first;
    for (int i = 0; i < n; ++i)
        cin >> d[i].second;
    sort(d, d + n);
    multiset<pair<int, int>> mset;
    for (int i = 0; i < n; ++i)
    {
        for (auto it = mset.begin(); it != mset.end();)
        {
            if (it->second <= d[i].second)
                it = mset.erase(it);
            else
                it++;
        }
        mset.insert(d[i]);
    }
    cout << mset.size();
    return 0;
}
