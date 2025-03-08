#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_5_4_1.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> h(n), w(k);
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    for (int i = 0; i < k; ++i)
        cin >> w[i];
    deque<int> mnq;
    int mx = -1;
    for (int i = 0; i < n; ++i)
    {
        if (!mnq.empty() && mnq.front() <= i - w[0])
            mnq.pop_front();
        while (!mnq.empty() && h[mnq.back()] >= h[i])
            mnq.pop_back();
        mnq.push_back(i);
        if (i >= w[0] - 1)
            mx = max(mx, h[mnq.front()]);
    }
    cout << mx;

    return 0;
}
