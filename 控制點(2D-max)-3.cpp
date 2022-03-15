#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

pair<int, int> d[N];

int main()
{
    freopen("P_4_14_5.in", "r", stdin);
    int n;
    cin >> n;
    vector<pair<int, int>> data;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        data.push_back({x, 0});
    }
    for (int i = 0; i < n; ++i)
        cin >> data[i].second;
    sort(data.begin(), data.end(), greater<pair<int, int>>());
    int maxy = -1;
    int total = 0;
    for (auto e : data)
    {
        if (e.second > maxy)
        {
            total++;
            maxy = e.second;
        }
    }
    cout << total;
    return 0;
}
