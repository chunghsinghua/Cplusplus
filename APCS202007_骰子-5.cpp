#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("Q_3_12_5.in", "r", stdin);
    int n, m, a, b, t;
    cin >> n >> m;
    vector<vector<int>> game(n + 1, vector<int>({1, 4, 2})); // top, front, right;
    while (m--)
    {
        cin >> a >> b;
        if (b == -1)
        {
            t = game[a][1];
            game[a][1] = game[a][0];
            game[a][0] = 7 - t;
        }
        else if (b == -2)
        {
            t = game[a][2];
            game[a][2] = game[a][0];
            game[a][0] = 7 - t;
        }
        else
            swap(game[a], game[b]);
    }
    for (int i = 1; i <= n; ++i)
        cout << game[i][0] << ' ';
    return 0;
}
