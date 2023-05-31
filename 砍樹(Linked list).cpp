#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

struct
{
    int pre, next;
    int alive;
    int c, h;
} tree[N];

queue<int> q;
void remove(int i)
{
    if (tree[i].alive == 0)
        return;
    int s = tree[i].pre, t = tree[i].next;
    if (tree[i].c - tree[i].h >= tree[s].c || tree[i].c + tree[i].h <= tree[t].c)
    {
        tree[i].alive = 0;
        q.push(i);
        tree[s].next = t;
        tree[t].pre = s;
    }
    return;
}

int main()
{
    freopen("P_3_6_4.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> tree[i].c;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tree[i].h;
        tree[i].alive = 1;
        tree[i].pre = i - 1;
        tree[i].next = i + 1;
    }
    tree[0].c = 0, tree[0].h = 1000000010;
    tree[n + 1].c = l, tree[n + 1].h = 1000000010;
    for (int i = 1; i <= n; ++i)
        remove(i);
    int total = 0, high = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        total++;
        high = max(high, tree[v].h);

        remove(tree[v].pre);
        remove(tree[v].next);
    }

    cout << total << "\n"
         << high;

    return 0;
}
