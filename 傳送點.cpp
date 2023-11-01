#include <bits/stdc++.h>

using namespace std;

#define N 1000010
typedef long long ll;

int s[N], d[N];

int main()
{
    // freopen("Q_7_5_5.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, p, l, r;
    cin >> n >> p >> l >> r;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
        if (s[i] < 0 || s[i] >= n)
            s[i] = n;
    }
    memset(d, -1, sizeof(d));
    queue<int> que;
    que.push(0);
    d[0] = 0;
    while (!que.empty() && d[p] < 0)
    {
        int v = que.front();
        que.pop();
        int nxt = v + r;
        if (nxt < n && s[nxt] < n && d[s[nxt]] < 0)
        {
            d[s[nxt]] = d[v] + 1;
            que.push(s[nxt]);
        }
        nxt = v - l;
        if (nxt >= 0 && s[nxt] < n && d[s[nxt]] < 0)
        {
            d[s[nxt]] = d[v] + 1;
            que.push(s[nxt]);
        }
    }
    cout << d[p];

    return 0;
}
