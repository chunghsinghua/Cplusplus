#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int main()
{
    freopen("Q_2_7_2.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    int ref = (1 << m) - 1;
    set<int> ss;
    int cnt = 0;

    while (n--)
    {
        string s;
        cin >> s;
        int t = 0;
        for (auto e : s)
        {
            int tt = e - 'A';
            t = t | (1 << tt);
        }
        ss.insert(t);
        if (ss.find(ref - t) != ss.end())
            cnt++;
    }

    cout << cnt;
    return 0;
}
