#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int main()
{
    // freopen("P_8_14_5.in", "r", stdin);
    string s;
    while (cin >> s)
    {
        string s1(s), s2(s);
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            int num = s[i] - '0';
            if (num & 1)
                continue;

            // s1 is big;
            s1[i] += 1;
            for (int j = i + 1; j < len; ++j)
                s1[j] = '1';

            // s2 is small;
            s2[i] -= 1;
            if (s2[i] < '0')
            {
                s2[i] = '9';
                int j = i - 1;
                while (j > 0 && s2[j] == '1')
                    s2[j--] = '9';

                s2[j] -= 2;
                if (s2[j] < '0')
                    s2[j] = '0';
            }
            for (int j = i + 1; j < len; ++j)
                s2[j] = '9';

            break;
        }
        cout << min(stoll(s1) - stoll(s), stoll(s) - stoll(s2)) << '\n';
    }
    return 0;
}
