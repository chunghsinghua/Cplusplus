#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

pair<int, int> d[N];

int main()
{
    freopen("P_4_15_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i].first >> d[i].second;
    sort(d, d + n);
    int mind = 2e8 + 10;
    multimap<int, int> mmap; // y,x
    for (int i = 0; i < n; ++i)
    {
        auto it = mmap.lower_bound(d[i].second - mind);
        while (it != mmap.end() && it->first <= d[i].second + mind)
        {
            if (it->second < d[i].first - mind)
            {
                it = mmap.erase(it);
                continue;
            }
            mind = min(mind, abs(d[i].first - it->second) + abs(d[i].second - it->first));
            it++;
        }

        mmap.insert({d[i].second, d[i].first});
    }
    cout << mind;
    return 0;
}
