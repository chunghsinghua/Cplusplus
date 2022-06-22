#include <bits/stdc++.h>

using namespace std;

#define N 100010
#define oo 1000000010
typedef long long ll;

int c[N], h[N];

int main()
{
    freopen("p_3_6_2.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    c[0] = 0, h[0] = oo;
    c[n + 1] = l, h[n + 1] = oo;
    int high = 0, total = 0;
    stack<int> stk;
    stk.push(0);
    for (int i = 1; i <= n; ++i)
    {
        if (c[i] - h[i] >= c[stk.top()] || c[i] + h[i] <= c[i + 1])
        {
            total++;
            high = max(high, h[i]);
            while (c[stk.top()] + h[stk.top()] <= c[i + 1])
            {
                total++;
                high = max(high, h[stk.top()]);
                stk.pop();
            }
        }
        else
            stk.push(i);
    }
    cout << total << "\n"
         << high;
    return 0;
}
