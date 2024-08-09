#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int main()
{
    // freopen("Q_6_10_3.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    string e[m], s, t;
    for (int i = 0; i < m; ++i)
        cin >> e[i];
    cin >> t;
    for (int i = m - 1; i >= 0; --i)
    {
        s = "";
        int cnt1 = 0;
        for (auto x : e[i])
            if (x == '1')
                cnt1++;

        for (int j = n - 1; j >= 0; --j)
        {
            if (e[i][j] == '0')
                s = t[j] + s;
            else
                s += t[j];
        }

        if (cnt1 % 2)
        {
            if (n % 2)
                s = s.substr(n / 2 + 1, n / 2) + s[n / 2] + s.substr(0, n / 2);
            else
                s = s.substr(n / 2, n / 2) + s.substr(0, n / 2);
        }

        t = s;
    }
    cout << s;
    return 0;
}
