#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_3_4_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];

    d[0] = INT_MAX;
    stack<int> stk;
    stk.push(0);
    ll total = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (d[stk.top()] <= d[i])
            stk.pop();
        total += i - stk.top();
        stk.push(i);
    }
    cout << total;
    return 0;
}
