#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

void fun(string ret, string &s, int t, map<string, bool> &mp)
{
    if (t == 0)
    {
        mp.insert({ret, false});
        return;
    }
    for (int i = 0; i < s.size(); ++i)
    {
        string ret2 = ret + s[i];
        fun(ret2, s, t - 1, mp);
    }
}

int main()
{
    // freopen("P_5_4_3.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string alpha, s;
    int l, leng;
    cin >> alpha >> l >> s;
    leng = s.size();
    map<string, bool> mp;
    fun("", alpha, l, mp);
    string t;
    for (int i = 0; i <= leng - l; ++i)
    {
        t = s.substr(i, l);
        mp[t] = true;
    }
    for (auto it = mp.begin(); it != mp.end(); ++it)
        if (!it->second)
        {
            cout << it->first;
            break;
        }
    return 0;
}
