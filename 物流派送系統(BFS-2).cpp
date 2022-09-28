#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;
vector<int> child[N];
int parent[N], wei[N], h[N], step[N];

int main()
{
    freopen("P_8_2_2.in", "r", stdin);
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
    int longest = 0, maxstep = 0;
    while (que.size() < n)
    {
        int v = que[head++];
        for (int ch : child[v])
        {
            que.push_back(ch);
            h[ch] = h[v] + wei[ch];
            longest = max(longest, h[ch]);
            step[ch] = step[v] + 1;
            maxstep = max(maxstep, step[ch]);
        }
    }

    cout << longest << "\n"
         << maxstep;

    return 0;
}
