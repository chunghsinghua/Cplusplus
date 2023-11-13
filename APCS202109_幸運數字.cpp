#include <bits/stdc++.h>

using namespace std;

#define N 300010
typedef long long ll;

ll a[N], psum[N];

bool cmp(int x, int y)
{
    return a[x] > a[y];
}

int main()
{
    // freopen("P_4_14_5.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
        v.push_back(i);
    }
    sort(v.begin(), v.end(), cmp);
    int le = 1, ri = n;
    ll lesum, risum, k;
    while (le != ri)
    {
        while (v.back() < le || v.back() > ri)
            v.pop_back();
        k = v.back();
        v.pop_back();
        lesum = psum[k - 1] - psum[le - 1];
        risum = psum[ri] - psum[k];
        if (lesum > risum)
            ri = k - 1;
        else
            le = k + 1;
    }
    cout << a[le];
    return 0;
}
