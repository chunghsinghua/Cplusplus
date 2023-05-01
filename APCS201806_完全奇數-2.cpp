#include <bits/stdc++.h>

using namespace std;

#define N 300010
typedef long long ll;

int main()
{
    // freopen("Q_2_12_2.in", "r", stdin);
    string s;
    while (cin >> s)
    {
        int len = s.size();
        string s1(s), s2(s);
        for (int i = 0; i < len; ++i)
        {
            if ((s[i] - '0') % 2)
                continue;

            s1[i] += 1;
            for (int j = i + 1; j < len; ++j)
                s1[j] = '1';
            //===========================
            if (s2[i] == '0')
            {
                s2[i] = '9';

                if (s2[i - 1] == '1')
                {
                    int j = i - 1;
                    while (j > 0 && s2[j] == '1')
                    {
                        s2[j] = '9';
                        j--;
                    }
                    s2[j] -= 2;
                    if ((s2[j] - '0') < 0)
                        s2[j] = '0';
                }
                else
                    s2[i - 1] -= 2;
            }
            else
                s2[i] -= 1;
            for (int j = i + 1; j < len; ++j)
                s2[j] = '9';

            break;
        }

        cout << min(stoll(s1) - stoll(s), stoll(s) - stoll(s2)) << '\n';
    }
    return 0;
}
