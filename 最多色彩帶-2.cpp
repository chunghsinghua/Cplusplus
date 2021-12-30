#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N];
map<int, int> mp;

int main()
{
    freopen("P_3_9_1.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    for (int i = 0; i < l; ++i)
        mp[d[i]]++;
    int ans = mp.size();
    for (int i = l, left = 0; i < n; ++i, ++left)
    {
        mp[d[i]]++;
        mp[d[left]]--;
        if (mp[d[left]] == 0)
            mp.erase(d[left]);
        ans = max(ans, (int)mp.size());
    }
    cout << ans;
    return 0;
}
