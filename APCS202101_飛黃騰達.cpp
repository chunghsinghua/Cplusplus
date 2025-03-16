#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;
int main()
{
    // freopen("P_6_15_5.in", "r", stdin);
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());
    vector<int> last;
    for (int i = 0; i < n; ++i)
    {
        auto it = upper_bound(last.begin(), last.end(), p[i].second);
        if (it == last.end())
            last.push_back(p[i].second);
        else
            *it = p[i].second;
    }
    cout << last.size();
    return 0;
}
