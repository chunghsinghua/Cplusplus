#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_3_8_5.in", "r", stdin);
    int n;
    cin >> n;
    vector<pair<int, int>> point(n);
    for (int i = 0; i < n; ++i)
        cin >> point[i].first >> point[i].second;
    sort(point.begin(), point.end());
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
            if (point[i].second <= point[j].second)
                dp[j] = max(dp[j], dp[i] + 1);
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}
