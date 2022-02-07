#include <bits/stdc++.h>
using namespace std;

#define N 200010
typedef long long ll;

pair<int, int> d[N];

int main()
{
    freopen("Q_3_13_2.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
        cin >> d[i].first;
    for (int i = 0; i < n; ++i)
        cin >> d[i].second;
    sort(d, d + n);
    int ans = -1;
    multiset<int> mset;
    mset.insert(d[0].second);
    for (int left = 0, right = 1; right < n; ++right)
    {
        mset.insert(d[right].second);
        while (d[right].first - d[left].first > l)
        {
            mset.erase(d[left].second);
            left++;
        }
        ans = max(ans, *mset.rbegin() - *mset.begin());
    }
    cout << ans;

    return 0;
}
