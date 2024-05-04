#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

vector<vector<int>> adj(N);

bool bfs(vector<vector<int>> &vec, vector<int> &col, int v)
{
    col[v] = 1;
    queue<int> que;
    que.push(v);
    while (!que.empty())
    {
        int p = que.front();
        que.pop();
        for (int e : vec[p])
        {
            if (col[e] < 0)
            {
                col[e] = col[p] ^ 1;
                que.push(e);
            }
            else if (col[e] == col[p])
                return false;
        }
    }
    return true;
}

bool bipar(vector<vector<int>> &vec, int n)
{
    vector<int> col(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (col[i] >= 0)
            continue;
        bool check = bfs(vec, col, i);
        if (!check)
            return false;
    }
    return true;
}

int main()
{
    // freopen("Q_8_16_5.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, p, k;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> p >> k;
    vector<vector<int>> pp(p, vector<int>(k * 2, 0));
    for (int i = 0; i < p; ++i)
        for (int j = 0; j < k * 2; ++j)
            cin >> pp[i][j];
    vector<pair<int, int>> test;
    test.push_back({0, p - 1});
    vector<int> ans;

    while (!test.empty())
    {
        auto t = test.back();
        test.pop_back();
        int le = t.first, ri = t.second;
        vector<vector<int>> temp(n);
        for (int i = 0; i < n; ++i)
            for (int e : adj[i])
                temp[i].push_back(e);

        for (int i = le; i <= ri; ++i)
        {
            for (int j = 0; j < k * 2; j += 2)
            {
                temp[pp[i][j]].push_back(pp[i][j + 1]);
                temp[pp[i][j + 1]].push_back(pp[i][j]);
            }
        }
        if (!bipar(temp, n))
        {
            if (le == ri)
                ans.push_back(le + 1);
            else
            {
                int mid = (le + ri) / 2;
                test.push_back({le, mid});
                test.push_back({mid + 1, ri});
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (int e : ans)
        cout << e << '\n';
    return 0;
}
