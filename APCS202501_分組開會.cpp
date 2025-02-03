#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("Q_3_5_5.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<ll> vec(n), d(n), pmin(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    int med = k / 2;
    int right = k - 1, left = 0;
    for (int i = left; i <= right; ++i)
        d[right] += abs(vec[i] - vec[med]);
    right++, left++, med++;
    for (; right < n; ++left, ++right, ++med)
    {
        d[right] = d[right - 1];
        d[right] -= (vec[med - 1] - vec[left - 1]);
        d[right] += vec[right] - vec[med];
        d[right] += (med - left) * (vec[med] - vec[med - 1]);
        d[right] -= (right - med) * (vec[med] - vec[med - 1]);
    }
    pmin[k - 1] = d[k - 1];
    for (int i = k; i < n; ++i)
        pmin[i] = min(pmin[i - 1], d[i]);
    ll mn = 1e18;
    for (int i = k + k - 1; i < n; ++i)
        mn = min(mn, d[i] + pmin[i - k]);
    cout << mn;
    return 0;
}
