#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int c[N];

int main()
{
    freopen("P_3_10_4.in", "r", stdin);
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
        mp[c[i]] = 0;
    }
    int totalc = mp.size();
    int ncolor = 0;
    int ans = n;
    for (int right = 0, left = 0; right < n; ++right)
    {
        int color = c[right];
        mp[color]++;
        if (mp[color] == 1)
            ncolor++;
        while (mp[c[left]] >= 2)
        {
            mp[c[left]]--;
            left++;
        }
        if (ncolor == totalc)
            ans = min(ans, right - left + 1);
    }
    cout << ans;
    return 0;
}
