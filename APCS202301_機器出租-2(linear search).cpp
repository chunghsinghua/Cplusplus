#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_6_7_5.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i].second;
    for (int i = 0; i < n; ++i)
        cin >> vec[i].first;
    sort(vec.begin(), vec.end());
    vector<int> record(k, -1);
    int cnt = 0;
    for (auto e : vec)
    {
        int best = -2, idx = -1;
        for (int i = 0; i < k; ++i)
        {
            if (e.second > record[i] && record[i] > best)
            {
                best = record[i];
                idx = i;
            }
        }
        if (idx >= 0)
        {
            record[idx] = e.first;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
