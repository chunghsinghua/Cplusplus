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
            string t1 = s.substr(0, m), t2 = s.substr(m, len - m);
            for (int i = 0; i < t1.size(); ++i)
                s[2 * i] = t1[i];
            for (int i = 0; i < t2.size(); ++i)
                s[2 * i + 1] = t2[i];
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
