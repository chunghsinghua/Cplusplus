#include <bits/stdc++.h>
using namespace std;

#define N 510
typedef long long ll;

int main()
{
    freopen("Q_3_12_3.in", "r", stdin);
    int n, m, cnt = 0;
    cin >> m >> n;
    vector<int> vec(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
        mp[vec[i]] = -1;
    }
    int le = 0;
    for (int i = 0; i < n; ++i)
    {
        if (mp[vec[i]] >= le)
            le = mp[vec[i]] + 1;
        mp[vec[i]] = i;
        if (i - le + 1 == m)
            cnt++;
    }
    cout << cnt;
    return 0;
}
