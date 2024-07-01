#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_5_4_3.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    const int m = 2000;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    int psum = 0, ssum = 0, oddcnt = 0;
    vector<int> bal[m + m + 1];
    bal[m].push_back(0);
    for (int i = 0; i < n; ++i)
    {
        psum += vec[i];
        if (vec[i] & 1)
            oddcnt++;
        else
            oddcnt--;
        bal[m + oddcnt].push_back(psum);
    }
    if (k > psum)
        k = psum;
    oddcnt = 0;
    while (bal[m].back() > k)
        bal[m].pop_back();
    int ans = bal[m].back(), idx, ridx;
    for (int i = n - 1; i >= 0; --i)
    {
        ssum += vec[i];
        if (vec[i] & 1)
            oddcnt++;
        else
            oddcnt--;
        if (abs(oddcnt) > m)
            continue;
        ridx = m - oddcnt;
        if (bal[ridx].empty())
            continue;
        idx = distance(bal[ridx].begin(), upper_bound(bal[ridx].begin(), bal[ridx].end(), k - ssum)) - 1;
        if (idx < 0)
            continue;
        ans = max(ans, ssum + bal[ridx][idx]);
    }
    cout << ans;
    return 0;
}
