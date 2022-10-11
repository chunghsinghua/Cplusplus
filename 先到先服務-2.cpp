#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    freopen("Q_4_8_5.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    priority_queue<ll> pq;
    int i;
    int t;
    for (i = 0; i < m; ++i)
    {
        cin >> t;
        pq.push(-t);
    }
    for (; i < n; ++i)
    {
        cin >> t;
        t += (-pq.top());
        pq.pop();
        pq.push(-t);
    }
    while (pq.size() > 1)
        pq.pop();
    cout << -pq.top();
    return 0;
}
