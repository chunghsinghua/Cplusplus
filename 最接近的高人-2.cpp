#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_3_4_3.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];

    ll total = 0;
    d[0] = INT_MAX;
    multimap<int, int> mmp;
    for (int i = n; i >= 0; --i)
    {
        auto it = mmp.begin();
        while (it != mmp.end() && it->first < d[i])
        {
            total += it->second - i;
            it = mmp.erase(it);
        }
        mmp.insert({d[i], i});
    }
    cout << total;
    return 0;
}
