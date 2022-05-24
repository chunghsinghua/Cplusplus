#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int d[N];

int main()
{
    freopen("P_2_11_5.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    set<int> s;
    s.insert(0);
    int psum = 0, temp, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        psum += temp;
        auto it = s.lower_bound(psum - k);
        if (it != s.end())
            ans = max(ans, psum - *it);

        s.insert(psum);
    }
    cout << ans;
    return 0;
}
