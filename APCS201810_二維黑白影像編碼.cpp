#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int idx = -1;
int len;
string s;

int fun(int n)
{
    idx++;
    if (idx >= len)
        return 0;
    if (s[idx] == '0')
        return 0;
    if (s[idx] == '1')
        return n * n;
    if (s[idx] == '2')
    {
        int sum = 0;
        for (int i = 0; i < 4; ++i)
        {
            sum += fun(n / 2);
        }
        return sum;
    }
}

int main()
{
    freopen("q_1_5_5.in", "r", stdin);
    int n;
    cin >> s >> n;
    len = s.size();
    cout << fun(n);
    return 0;
}
