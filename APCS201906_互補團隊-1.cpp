#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    freopen("Q_2_7_2.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    int ff = (1 << m) - 1;
    string t;
    set<int> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        int len = t.size();
        int team = 0;
        for (int j = 0; j < len; ++j)
            team |= (1 << (t[j] - 'A'));
        s.insert(team);
    }
    int ans = 0;
    for (auto p : s)
        if (s.find(ff - p) != s.end())
            ans++;
    cout << ans / 2;

    return 0;
}
