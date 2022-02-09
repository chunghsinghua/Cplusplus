#include <bits/stdc++.h>
using namespace std;

#define N 1010
typedef long long ll;

ll s[N], t[N];
int lose[N];

int main()
{
    // freopen("p_1_3_5.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    vector<int> v, v1, v2;
    int idx;
    for (int i = 0; i < n; ++i)
    {
        cin >> idx;
        v.push_back(idx);
    }
    while (v.size() > 1)
    {
        for (int i = 0; i <= v.size() - 2; i += 2)
        {
            int x = v[i], y = v[i + 1];
            ll a = s[x], b = t[x], c = s[y], d = t[y];
            if (a * b >= c * d)
            {
                s[x] = a + c * d / (2 * b);
                t[x] = b + c * d / (2 * a);
                s[y] = c + c / 2;
                t[y] = d + d / 2;
                v1.push_back(x);
                lose[y]++;
                if (lose[y] < m)
                    v2.push_back(y);
            }
            else
            {
                s[y] = c + a * b / (2 * d);
                t[y] = d + a * b / (2 * c);
                s[x] = a + a / 2;
                t[x] = b + b / 2;
                v1.push_back(y);
                lose[x]++;
                if (lose[x] < m)
                    v2.push_back(x);
            }
        }
        if (v.size() % 2)
            v1.push_back(v.back());
        v = v1;
        for (int p : v2)
            v.push_back(p);
        v1.clear();
        v2.clear();
    }
    cout << v.front();
    return 0;
}
