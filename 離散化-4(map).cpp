#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int num[N];

int main()
{
    freopen("P_2_1_2.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    vector<int> t(num, num + n);
    map<int, int> mp;
    for (int e : t)
        mp[e] = 0;
    int idx = 0;
    for (auto &e : mp)
        e.second = idx++;

    for (int i = 0; i < n; ++i)
        cout << mp[num[i]] << ' ';

    return 0;
}
