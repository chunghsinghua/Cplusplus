#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int me[N], enemy[N];

int main()
{
    freopen("P_4_2_1.in", "r", stdin);
    int n;
    cin >> n;
    int ans = 0;
    int t;
    priority_queue<int> me, enemy;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        enemy.push(t);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        me.push(t);
    }
    while (!me.empty())
    {
        while (!enemy.empty() && enemy.top() >= me.top())
            enemy.pop();
        if (enemy.empty())
            break;
        ans++;
        me.pop();
        enemy.pop();
    }
    cout << ans;
    return 0;
}
