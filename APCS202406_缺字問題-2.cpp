#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

void fun(string s, int l, string &alpha, int n, map<string, bool> &mp)
{
    if (l == 0)
    {
        mp.insert({s, false});
        return;
    }
    for (int i = 0; i < n; ++i)
        fun(s + alpha[i], l - 1, alpha, n, mp);
    return;
}

int main()
{
    // freopen("p_1_1_5.in", "r", stdin);
    int k, l, leng, kl = 1;
    string s, alpha, t;
    cin >> alpha >> l >> s;
    k = alpha.size();
    leng = s.size();
    map<string, bool> mp;
    fun("", l, alpha, k, mp);
    for (int i = 0; i <= leng - l; ++i)
    {
        t = s.substr(i, l);
        mp[t] = true;
    }
    for (auto e : mp)
    {
        if (!e.second)
        {
            cout << e.first;
            break;
        }
    }
    return 0;
}
