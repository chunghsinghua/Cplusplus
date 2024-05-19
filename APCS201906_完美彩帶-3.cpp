#include <bits/stdc++.h>
using namespace std;

#define N 510
typedef long long ll;

int main()
{
    freopen("Q_3_12_5.in", "r", stdin);
    int n, m;
    cin >> m >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    set<int> s;
    int le = 0, cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s.find(vec[i]) != s.end())
        {
            while (vec[le] != vec[i])
            {
                s.erase(vec[le]);
                le++;
            }
            le++;
        }
        else
            s.insert(vec[i]);
        if (i - le + 1 == m)
            cnt++;
    }
    cout << cnt;
    return 0;
}
