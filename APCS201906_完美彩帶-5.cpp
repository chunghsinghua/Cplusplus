#include <bits/stdc++.h>
using namespace std;

#define N 510
typedef long long ll;

int main()
{
    freopen("Q_3_12_5.in", "r", stdin);
    int n, m, cnt = 0;
    cin >> m >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    vector<int> tmp(vec.begin(), vec.end());
    sort(tmp.begin(), tmp.end());
    vector<int> mp;
    mp.push_back(tmp[0]);
    for (int i = 1; i < n; ++i)
        if (tmp[i] != tmp[i - 1])
            mp.push_back(tmp[i]);
    for (int i = 0; i < n; ++i)
        vec[i] = distance(mp.begin(), lower_bound(mp.begin(), mp.end(), vec[i]));
    vector<int> last(mp.size(), -1);
    int le = 0;
    for (int i = 0; i < n; ++i)
    {
        if (last[vec[i]] >= le)
            le = last[vec[i]] + 1;
        else
            last[vec[i]] = i;
        if (i - le + 1 == m)
            cnt++;
    }
    cout << cnt;
    return 0;
}
