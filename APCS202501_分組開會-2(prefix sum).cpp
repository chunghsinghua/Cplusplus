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
    vector<ll> psum(vec.begin(), vec.end());
    for (int i = 1; i < n; ++i)
        psum[i] += psum[i - 1];
    int med = k / 2;
    int right = k - 1, left = 0;
    d[right] = psum[right] - psum[med] - psum[med - 1] + 0 + vec[med] * (med + med - left - right);
    right++, left++, med++;
    for (; right < n; ++left, ++right, ++med)
    {
        d[right] = psum[right] - psum[med] - psum[med - 1] + psum[left - 1] + vec[med] * (med + med - left - right);
    }
    pmin[k - 1] = d[k - 1];
    for (int i = k; i < n; ++i)
        pmin[i] = min(pmin[i - 1], d[i]);
    ll mn = 1e18;
    cout << mn << endl;
    for (int i = k + k - 1; i < n; ++i)
        mn = min(mn, d[i] + pmin[i - k]);
    cout << mn;
    return 0;
}
