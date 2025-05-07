#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<string> e(m);
    for (int i = 0; i < m; ++i)
        cin >> e[i];
    string s(n, '0'), t;
    cin >> t;
    for (int k = m - 1; k >= 0; --k)
    {
        int head = 0, tail = n - 1, n1 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (e[k][i] == '1')
            {
                s[tail--] = t[i];
                n1++;
            }
            else
                s[head++] = t[i];
        }
        if (n1 & 1)
        {
            int after = n / 2;
            if (n & 1)
                after++;
            for (int i = 0, j = after; j < n; ++i, ++j)
                swap(s[i], s[j]);
        }
        s.swap(t);
    }
    cout << t;
    return 0;
}
