#include <bits/stdc++.h>
using namespace std;

#define N 300010
typedef long long ll;

int main()
{
    // freopen("P_8_14_1.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n + 1), psum(n + 1), vec(n);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
        vec[i - 1] = i;
    }
    sort(vec.begin(), vec.end(), [&a](int x, int y)
         { return a[x] > a[y]; });
    int le = 1, ri = n;
    while (le < ri)
    {
        while (vec.back() < le || vec.back() > ri)
            vec.pop_back();
        int idx = vec.back();
        vec.pop_back();
        if (psum[ri] - psum[idx] >= psum[idx - 1] - psum[le - 1])
            le = idx + 1;
        else
            ri = idx - 1;
    }
    cout << a[le];
    return 0;
}
