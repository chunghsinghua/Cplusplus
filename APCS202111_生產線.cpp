#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int main()
{
    // freopen("P_8_11_3.in", "r", stdin);
    int n, m, l, r, w;
    cin >> n >> m;
    vector<int> t(n), work(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> l >> r >> w;
        l--;
        work[l] += w;
        work[r] -= w;
    }
    for (int i = 1; i < n; ++i)
        work[i] += work[i - 1];
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    sort(t.begin(), t.end());
    sort(work.begin(), work.end(), greater<int>());
    ll tot = 0;
    for (int i = 0; i < n; ++i)
        tot += t[i] * work[i];
    cout << tot;
    return 0;
}
