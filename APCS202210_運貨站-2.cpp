#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    int r, c, n;
    cin >> r >> c >> n;
    vector<int> record(r), h({4, 1, 2, 2, 3}), area({4, 3, 4, 4, 5});
    vector<vector<int>> t(5);
    t[0] = {1, 1, 1, 1}, t[1] = {3}, t[2] = {2, 2}, t[3] = {1, 3}, t[4] = {1, 2, 2};
    char type;
    int y, tot = 0, cnt = 0;
    while (n--)
    {
        cin >> type >> y;
        type -= 'A';
        int mx = 0;
        for (int i = 0; i < h[type]; ++i)
            mx = max(mx, record[i + y] + t[type][i]);
        if (mx > c)
            cnt++;
        else
        {
            for (int i = 0; i < h[type]; ++i)
                record[y + i] = mx;
            tot += area[type];
        }
    }
    cout << r * c - tot << ' ' << cnt;
    return 0;
}
