#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

struct G
{
    int f, back, t, bottom, r, l;
};

int main()
{
    // freopen("p_1_1_5.in", "r", stdin);
    int n, m, a, b, t;
    cin >> n >> m;
    vector<G> game(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        game[i].t = 1, game[i].bottom = 6;
        game[i].f = 4, game[i].back = 3;
        game[i].r = 2, game[i].l = 5;
    }
    while (m--)
    {
        cin >> a >> b;
        if (a > 0 && b > 0)
            swap(game[a], game[b]);
        else if (b == -1)
        {
            t = game[a].t;
            game[a].t = game[a].back;
            game[a].back = game[a].bottom;
            game[a].bottom = game[a].f;
            game[a].f = t;
        }
        else if (b == -2)
        {
            t = game[a].r;
            game[a].r = game[a].t;
            game[a].t = game[a].l;
            game[a].l = game[a].bottom;
            game[a].bottom = t;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << game[i].t << ' ';
    return 0;
}
