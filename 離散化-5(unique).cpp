#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int num[N];

int main()
{
    freopen("P_2_1_1.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    vector<int> t(num, num + n);
    sort(t.begin(), t.end());
    auto end_it = unique(t.begin(), t.end());
    map<int, int> mp;
    for (auto it = t.begin(); it != end_it; it++)
        mp[*it] = 0;
    int idx = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it)
        it->second = idx++;

    for (int i = 0; i < n; ++i)
        cout << mp[num[i]] << ' ';

    return 0;
}
