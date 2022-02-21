#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_4_7_1.in", "r", stdin);
    int n;
    cin >> n;
    priority_queue<ll> pq;
    ll temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        pq.push(-temp);
    }
    ll ans = 0;
    while (pq.size() > 1)
    {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    cout << -pq.top() << "\n"
         << -ans;
    return 0;
}
