#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_5_4_3.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, L;
    cin >> n >> L;
    vector<pair<int, int>> vec(n + 1);
    vec[0] = {0, 0};
    for (int i = 1; i <= n; ++i)
        cin >> vec[i].first >> vec[i].second;
    vec.push_back({L, 0});
    sort(vec.begin(), vec.end());
    vector<int> le(n + 2), ri(n + 2);
    for (int i = 1; i <= n; ++i)
        le[i] = i - 1;
    for (int i = 1; i <= n; ++i)
        ri[i] = i + 1;
    vector<int> seq(n);
    for (int i = 1; i <= n; ++i)
        seq[vec[i].second - 1] = i;
    ll tot = 0, l, r;
    for (int i = n - 1; i >= 0; --i)
    {
        l = le[seq[i]], r = ri[seq[i]];
        tot += vec[r].first - vec[l].first;
        ri[l] = r;
        le[r] = l;
    }
    cout << tot;
    return 0;
}
