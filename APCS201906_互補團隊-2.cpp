#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

vector<int> adj[N];
int mark[N], p[N];

int dfs(int root)
{
    int num = 0;
    for (int e : adj[root])
        num += dfs(e);
    if (mark[root])
    {
        num++;
        mark[p[root]] = 0;
    }
    return num;
}

int main()
{
    freopen("Q_2_7_3.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    set<int> s;
    for (int i = 0; i < n; ++i)
    {
        string ss;
        cin >> ss;
        int t = 0;
        for (auto e : ss)
            t |= (1 << (e - 'A'));
        s.insert(t);
    }
    int ff = (1 << m) - 1;
    int cnt = 0;
    while (!s.empty())
    {
        if (s.find(ff - *s.begin()) != s.end())
            cnt++;
        s.erase(s.begin());
    }
    cout << cnt;
    return 0;
}
