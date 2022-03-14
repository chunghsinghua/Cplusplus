#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

pair<int, int> d[N];

int main()
{
    freopen("P_4_14_1.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i].first;
    for (int i = 0; i < n; ++i)
        cin >> d[i].second;
    stack<int> stk;
    sort(d, d + n);
    for (int i = 0; i < n; ++i)
    {
        while (!stk.empty() && d[i].second >= stk.top())
            stk.pop();
        stk.push(d[i].second);
    }
    cout << stk.size();
    return 0;
}
