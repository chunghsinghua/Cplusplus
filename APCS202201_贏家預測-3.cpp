#include <bits/stdc++.h>

using namespace std;

#define N 1010
typedef long long ll;

struct Attr
{
    ll s, t;
    int lose;
} group[N];

int main()
{
    // freopen("P_6_19_5.in", "r", stdin);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> group[i].s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> group[i].t;
        group[i].lose = 0;
    }
    vector<int> round;
    int t;
    for (int i = 1; i <= n; ++i)
    {
        cin >> t;
        round.push_back(t);
    }
    int cnt = 0;
    while (round.size() > 1)
    {
        vector<int> win, lose;
        for (int i = 0; i <= round.size() - 2; i += 2)
        {
            int idx1 = round[i], idx2 = round[i + 1];
            ll a = group[idx1].s, b = group[idx1].t, c = group[idx2].s, d = group[idx2].t;
            if (a * b >= c * d)
            {
                group[idx1].s = a + c * d / (2 * b);
                group[idx1].t = b + c * d / (2 * a);
                group[idx2].s = c + c / 2;
                group[idx2].t = d + d / 2;
                win.push_back(idx1);
                group[idx2].lose++;
                if (group[idx2].lose < m)
                    lose.push_back(idx2);
            }
            else
            {
                group[idx1].s = a + a / 2;
                group[idx1].t = b + b / 2;
                group[idx2].s = c + a * b / (2 * d);
                group[idx2].t = d + a * b / (2 * c);
                win.push_back(idx2);
                group[idx1].lose++;
                if (group[idx1].lose < m)
                    lose.push_back(idx1);
            }
        }
        if (round.size() % 2)
            win.push_back(round.back());
        swap(round, win);
        for (auto e : lose)
            round.push_back(e);
    }
    cout << round.front();
    return 0;
}
