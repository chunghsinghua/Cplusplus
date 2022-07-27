#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

pair<int, int> p[N];

int main()
{
    freopen("Q_3_13_5.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
        cin >> p[i].first;
    for (int i = 0; i < n; ++i)
        cin >> p[i].second;

    sort(p, p + n);
    multiset<int> mset;
    int mx = 0;

    for (int left = 0, right = 0; right < n; ++right)
    {
        mset.insert(p[right].second);
        while (p[right].first - p[left].first > l)
        {
            mset.erase(p[left].second);
            left++;
        }
        mx = max(mx, *mset.rbegin() - *mset.begin());
    }

    cout << mx;
    return 0;
}
