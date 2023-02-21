#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string ss[30];

int main()
{
    int k, q, r;
    cin >> k >> q >> r;
    cin >> ss[0];
    for (int i = 1; i <= q; ++i)
    {
        ss[i] = ss[i - 1];
        int t;
        for (int j = 0; j < k; ++j)
        {
            cin >> t;
            ss[i][t - 1] = ss[i - 1][j];
        }
    }
    for (int i = 0; i < r; ++i)
    {
        for (int j = 1; j <= q; ++j)
            cout << ss[j][i];
        cout << '\n';
    }
    return 0;
}
