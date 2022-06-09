#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;
vector<int> child[N];
int parent[N], wei[N], h[N];

int main()
{
    freopen("P_8_2_5.in", "r", stdin);
    int n, p, w;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> p >> w;
        parent[i] = p;
        wei[i] = w;
        child[p].push_back(i);
    }
    vector<int> que;
    int head = 0;
    que.push_back(0);
    while (que.size() < n)
    {
        int v = que[head++];
        for (int ch : child[v])
            que.push_back(ch);
    }
    for (int i = 1; i < n; ++i)
    {
        int v = que[i];
        h[v] = h[parent[v]] + wei[v];
    }
    cout << *max_element(h, h + n) << "\n";

    memset(h, 0, sizeof(h));
    for (int i = 1; i < n; ++i)
    {
        int v = que[i];
        h[v] = h[parent[v]] + 1;
    }
    cout << *max_element(h, h + n);

    return 0;
}
