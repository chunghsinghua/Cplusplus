#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_2_2_3.in", "r", stdin);
    int n;
    cin >> n;
    map<int, int> mp;

    for (int i = 0; i < n; ++i)
    {
        cin >> d[i];
        mp[d[i]];
    }
    int idx = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it)
        it->second = idx++;
    for (int i = 0; i < n; ++i)
        d[i] = mp.find(d[i])->second;

    for (int i = 0; i < n; ++i)
        cout << d[i] << " ";
    return 0;
}
