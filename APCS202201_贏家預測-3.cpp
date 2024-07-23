#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

struct game
{
    ll s, t, lose;
};

int main()
{
    // freopen("q_1_8_5.in", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    ll m, n, a, b, c, d, x, y;
    cin >> n >> m;
    vector<game> g(n + 1, {0, 0, 0});
    vector<int> seq(n), winteam, loseteam;
    for (int i = 1; i <= n; ++i)
        cin >> g[i].s;
    for (int i = 1; i <= n; ++i)
        cin >> g[i].t;
    for (int i = 0; i < n; ++i)
        cin >> seq[i];
    while (seq.size() > 1)
    {
        winteam.clear();
        loseteam.clear();
        for (int i = 0; i < seq.size(); i += 2)
        {
            if ((seq.size() & 1) && (i == seq.size() - 1))
            {
                winteam.push_back(seq[i]);
                break;
            }
            x = seq[i], y = seq[i + 1];
            a = g[x].s, b = g[x].t, c = g[y].s, d = g[y].t;
            if (a * b >= c * d)
            {
                g[x].s = a + (c * d) / (2 * b);
                g[x].t = b + (c * d) / (2 * a);
                g[y].s = c + c / 2;
                g[y].t = d + d / 2;
                winteam.push_back(x);
                g[y].lose++;
                if (g[y].lose < m)
                    loseteam.push_back(y);
            }
            else
            {
                g[y].s = c + (a * b) / (2 * d);
                g[y].t = d + (a * b) / (2 * c);
                g[x].s = a + a / 2;
                g[x].t = b + b / 2;
                winteam.push_back(y);
                g[x].lose++;
                if (g[x].lose < m)
                    loseteam.push_back(x);
            }
        }
        swap(winteam, seq);
        seq.insert(seq.end(), loseteam.begin(), loseteam.end());
    }
    cout << seq.front();
    return 0;
}
