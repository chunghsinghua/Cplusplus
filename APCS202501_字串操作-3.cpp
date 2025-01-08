#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_5_4_1.in", "r", stdin);
    string s;
    cin >> s;
    int len = s.size(), opn, op;
    int m = len / 2;
    cin >> opn;
    while (opn--)
    {
        cin >> op;
        if (op == 2)
        {
            string t(s);
            for (int to = 0, from = 0; from < m; ++from, to += 2)
                s[to] = t[from];
            for (int to = 1, from = m; from < len; ++from, to += 2)
                s[to] = t[from];
        }
        else if (op == 0)
        {
            for (int i = 1; i < len; i += 2)
                swap(s[i], s[i - 1]);
        }
        else
        {
            for (int i = 1; i < len; i += 2)
                if (s[i] < s[i - 1])
                    swap(s[i], s[i - 1]);
        }
    }
    cout << s;
    return 0;
}
