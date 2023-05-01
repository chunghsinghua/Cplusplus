#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("p_1_1_5.in", "r", stdin);
    string in;
    while (cin >> in)
    {
        string sin(in), bin(in);
        int len = in.size();
        for (int i = 0; i < len; ++i)
        {
            int x = in[i] - '0';
            if (x % 2 == 0)
            {
                bin[i] += 1;
                for (int j = i + 1; j < len; ++j)
                    bin[j] = '1';
                break;
            }
        }
        for (int i = 0; i < len; ++i)
        {
            int x = in[i] - '0';
            if (x % 2 == 0)
            {
                if (in[i] == '0')
                {
                    int idx = i - 1;
                    while (idx > 0 && sin[idx] == '1')
                    {
                        sin[idx] = '9';
                        idx--;
                    }
                    sin[idx] -= 2;
                    if (sin[idx] < '0')
                        sin[idx] = '0';
                    for (int j = i; j < len; ++j)
                        sin[j] = '9';
                    break;
                }
                else
                {
                    sin[i] -= 1;
                    for (int j = i + 1; j < len; ++j)
                        sin[j] = '9';
                    break;
                }
            }
        }
        cout << min(stoll(in) - stoll(sin), stoll(bin) - stoll(in)) << "\n";
    }
    return 0;
}
