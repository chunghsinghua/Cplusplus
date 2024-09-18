#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_3_1_5.in", "r", stdin);
    // clock_t startt, endt;
    // startt = clock();
    int m;
    cin >> m;
    string ss[m], t;
    set<string> s;
    for (int i = 0; i < m; ++i)
    {
        cin >> ss[i];
        s.insert(ss[i]);
    }
    int cnt = 0;
    for (string e : ss)
    {
        if (e.size() < 3)
            continue;
        int mid = e.size() / 2;
        for (int l = 1; l <= mid; ++l)
        {
            if (e.substr(0, l) == e.substr(e.size() - l, l))
                if (s.count(e.substr(l, e.size() - l - l)))
                    cnt++;
        }
    }
    cout << cnt;
    // endt = clock();
    // cout << '\n'
    //      << (float)(endt - startt) / CLOCKS_PER_SEC;
    return 0;
}
