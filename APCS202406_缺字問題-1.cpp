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
    for (int i = 0; i < l; ++i)
        p = p * k + mp[s[i]];
    tab[p] = true;
    for (int i = l; i < leng; ++i)
    {
        p = (p * k + mp[s[i]]) % kl;
        tab[p] = true;
    }
    string ret(l, '0');
    int i, j = l - 1;
    for (i = 0; i < kl && tab[i]; ++i)
        ;
    while (i)
    {
        ret[j--] = alpha[i % k];
        i /= k;
    }
    while (j >= 0)
        ret[j--] = alpha[0];
    cout << ret;
    return 0;
}
