#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int d[N];

int main()
{
    freopen("P_5_7_5.in", "r", stdin);
    int n;
    cin >> n;
    d[0] = d[n + 1] = 1;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];

    stack<int> stk;
    stk.push(0);
    ll mx = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        if (d[i] > d[stk.top()])
            stk.push(i);
        if (d[i] >= d[stk.top()])
            continue;
        while (d[i] < d[stk.top()])
        {
            ll height = d[stk.top()];
            stk.pop();
            mx = max(mx, (i - stk.top() - 1) * height);
        }
        stk.push(i);
    }
    cout << mx;
    return 0;
}
