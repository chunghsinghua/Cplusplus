#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_6_15_3.in", "r", stdin);
    int m;
    string s, t;
    cin >> m;
    int cnt = 0;
    vector<string> vec(m);
    for (int i = 0; i < m; ++i)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    for (int i = 0; i < m; ++i)
    {
        t = vec[i];
        if (t.size() < 3)
            continue;
        for (int l = 1; l <= t.size() / 2; ++l)
        {
            if (t.substr(0, l) == t.substr(t.size() - l, l))
            {
                bool check = binary_search(vec.begin(), vec.end(), t.substr(l, t.size() - l - l));
                if (check)
                    cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
