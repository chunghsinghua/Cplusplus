#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("Q_7_5_4.in", "r", stdin);
    // clock_t st, et;
    // st = clock();
    int n, p, l, r;
    cin >> n >> p >> l >> r;
    vector<int> vec(n), dis(n, -1);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
        if (vec[i] < 0 || vec[i] >= n)
            vec[i] = n;
    }
    queue<int> que;
    que.push(0);
    dis[0] = 0;
    int lp, rp;
    while (!que.empty() && dis[p] < 0)
    {
        int v = que.front();
        que.pop();
        lp = v - l;
        if (lp >= 0 && vec[lp] < n && dis[vec[lp]] < 0)
        {
            dis[vec[lp]] = dis[v] + 1;
            que.push(vec[lp]);
        }
        rp = v + r;
        if (rp < n && vec[rp] < n && dis[vec[rp]] < 0)
        {
            dis[vec[rp]] = dis[v] + 1;
            que.push(vec[rp]);
        }
    }
    cout << dis[p];
    // et = clock();
    // cout << '\n'
    //      << (float)(et - st) / CLOCKS_PER_SEC;
    return 0;
}
