#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

string s;
int idx = 0;

ll fun(int &head, int &tail)
{
    ll total = 0;
    head = -1, tail = -1;
    while (1)
    {
        if (idx >= s.size())
            return total;
        if (s[idx] == 'T')
        {
            ll t = stoi(s.substr(idx + 1, 2));
            if (head < 0)
                head = t;
            else
                total += abs(tail - t);
            tail = t;
            idx += 3;
        }
        else if (s[idx] == 'L')
        {
            ll t = stoi(s.substr(idx + 1, 1));
            idx += 2;
            int h, e;
            ll cost = fun(h, e);
            if (head < 0)
                head = h;
            else
                total += abs(h - tail);
            tail = e;
            total += cost * t + abs(h - e) * (t - 1);
        }
        else if (s[idx] == 'E')
        {
            idx += 1;
            return total;
        }
    }
}

int main()
{
    // freopen("P_8_7_3.in", "r", stdin);
    int h, e;
    cin >> s;
    ll total = fun(h, e);
    total += abs(10 - h);
    cout << total;
    return 0;
}
