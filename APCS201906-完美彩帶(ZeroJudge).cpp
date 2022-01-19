#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

string d[N];

int main()
{
    // freopen("Q_3_12_1.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    int ncolor = 0;
    for (int i = 0; i < m; ++i)
    {
        if (!mp[d[i]])
            ncolor++;
        mp[d[i]]++;
    }
    int ans = (ncolor == m);
    for (int left = 0, right = m; right < n; ++left, ++right)
    {
        mp[d[left]]--;
        if (!mp[d[left]])
            ncolor--;
        if (!mp[d[right]])
            ncolor++;
        mp[d[right]]++;

        ans += (ncolor == m);
    }
    cout << ans;
    return 0;
}
