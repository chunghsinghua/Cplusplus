#include <bits/stdc++.h>
using namespace std;

#define N 200010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_3_8_1.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    deque<int> deq;

    for (int i = 1; i <= l; ++i)
        deq.push_back(d[i]);
    int ans = *max_element(deq.begin(), deq.end()) - *min_element(deq.begin(), deq.end());

    for (int i = l + 1; i <= n; ++i)
    {
        deq.pop_front(), deq.push_back(d[i]);
        ans = max(ans, *max_element(deq.begin(), deq.end()) - *min_element(deq.begin(), deq.end()));
    }
    cout << ans;
    return 0;
}
