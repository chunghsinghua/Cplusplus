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
    int n, m;
    cin >> n >> m;
    vector<game> g(n + 1, {0, 0, 0});
    vector<int> seq(n);
    for (int i = 1; i <= n; ++i)
        cin >> g[i].s;
    for (int i = 1; i <= n; ++i)
        cin >> g[i].t;
    for (int i = 0; i < n; ++i)
        cin >> seq[i];
    while (seq.size() > 1)
    {
        vector<int> winner, loser;
        for (int i = 0; i + 1 < seq.size(); i += 2)
        {
            int win = seq[i], lose = seq[i + 1];
            if (g[win].s * g[win].t < g[lose].s * g[lose].t)
                swap(win, lose);
            ll a = g[win].s, b = g[win].t, c = g[lose].s, d = g[lose].t;
            g[win].s += (c * d) / (2 * b);
            g[win].t += (c * d) / (2 * a);
            g[lose].s += c / 2;
            g[lose].t += d / 2;
            winner.push_back(win);
            if (++g[lose].lose < m)
                loser.push_back(lose);
        }
        if (seq.size() % 2 == 1)
            winner.push_back(seq.back());
        seq.swap(winner);
        seq.insert(seq.end(), loser.begin(), loser.end());
    }
    cout << seq.front();
    return 0;
}
