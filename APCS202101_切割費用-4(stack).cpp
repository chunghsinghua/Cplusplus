#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("Q_3_5_3.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> seq(n);
    for (int i = 0; i < n; ++i)
        cin >> seq[i].first >> seq[i].second;
    sort(seq.begin(), seq.end());
    seq.push_back({l, 0});
    ll tot = 0, ord, pos;
    stack<pair<int, int>> stk;
    stk.push({0, 0});
    for (int i = 0; i < n + 1; ++i)
    {
        while (stk.top().second > seq[i].second)
        {
            tot += seq[i].first;
            stk.pop();
        }
        tot -= stk.top().first;
        stk.push(seq[i]);
    }
    cout << tot;
    return 0;
}
