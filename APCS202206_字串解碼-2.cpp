#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

struct Monster
{
    int r, c, s, t;
};

int main()
{
    // freopen("p_1_1_5.in", "r", stdin);
    int m, n, cnt1 = 0;
    cin >> m >> n;
    string e[m], t, s;
    for (int i = 0; i < m; ++i)
        cin >> e[i];
    cin >> t;
    for (int k = m - 1; k >= 0; --k)
    {
        s.clear();
        cnt1 = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (e[k][i] == '0')
            {
                s = t.back() + s;
                t.pop_back();
            }
            else
            {
                s += t.back();
                t.pop_back();
                cnt1++;
            }
        }
        if (cnt1 & 1)
        {
            if (n & 1)
                s = s.substr(n / 2 + 1, n / 2) + s[n / 2] + s.substr(0, n / 2);
            else
                s = s.substr(n / 2, n / 2) + s.substr(0, n / 2);
        }
        t.swap(s);
    }
    cout << t;
    return 0;
}
