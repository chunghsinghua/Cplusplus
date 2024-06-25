#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_5_4_3.in", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    string alpha, s;
    int l, k, kl = 1, leng, p = 0;
    cin >> alpha >> l >> s;
    k = alpha.size();
    leng = s.size();
    for (int i = 0; i < l; ++i)
        kl *= k;
    vector<bool> tab(kl, false);
    map<char, int> mp;
    for (int i = 0; i < k; ++i)
        mp[alpha[i]] = i;
    for (int i = 0; i <= leng - l; ++i)
    {
        p = 0;
        for (int j = 0; j < l; ++j)
            p = p * k + mp[s[i + j]];
        tab[p] = true;
    }
    string ret(l, '0');
    int i, j = 0;
    for (i = 0; i < kl && tab[i]; ++i)
        ;
    while (i)
    {
        ret[j++] = alpha[i % k];
        i /= k;
    }
    while (j < l)
        ret[j++] = alpha[0];
    reverse(ret.begin(), ret.end());
    cout << ret;
    return 0;
}
