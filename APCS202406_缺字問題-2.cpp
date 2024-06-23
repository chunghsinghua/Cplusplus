#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

void fun(string ret, string s, int t, map<string, int> &mp)
{
    if (t == 0)
    {
        mp.insert({ret, 0});
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
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    string alpha, s;
    int l;
    cin >> alpha >> l >> s;
    map<string, int> mp;
    fun("", alpha, l, mp);
    int leng = s.size();
    for (int i = 0; i < leng - (l - 1); ++i)
    {
        string t = s.substr(i, l);
        mp[t]++;
    }
    for (auto it = mp.begin(); it != mp.end(); ++it)
        if (!it->second)
        {
            cout << it->first;
            break;
        }
    return 0;
}
