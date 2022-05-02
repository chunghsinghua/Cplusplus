#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

ll sa[1 << 19], sb[1 << 19], num[1 << 19];
int rec(int a[], int len, ll sub[], int p)
{
    ll k = 0;
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < k; ++j)
            sub[k + j] = a[i] * sub[j] % p;
        sub[k + k] = a[i];
        k += k + 1;
    }
    return k;
}

ll exp(ll x, ll y, ll p)
{
    if (y == 0)
        return 1;
    if (y & 1)
        return x * exp(x, y - 1, p) % p;
    ll t = exp(x, y / 2, p);
    return t * t % p;
}

int main()
{
    freopen("P_2_9_2.in", "r", stdin);
    int n, p;
    cin >> n >> p;
    int a[30], b[30];
    int lena = n / 2;
    int lenb = n - lena;
    for (int i = 0; i < lena; ++i)
        cin >> a[i];
    for (int i = 0; i < lenb; ++i)
        cin >> b[i];
    int lensa = rec(a, lena, sa, p);
    int lensb = rec(b, lenb, sb, p);
    sort(sb, sb + lensb);
    int lensb2 = 1;
    num[0] = 1;
    for (int i = 1; i < lensb; ++i)
    {
        if (sb[i] != sb[i - 1])
        {
            sb[lensb2] = sb[i];
            num[lensb2] = 1;
            lensb2++;
        }
        else
            num[lensb2 - 1]++;
    }
    ll ans = 0;
    if (sb[0] == 1)
        ans = num[0] % p;

    for (int i = 0; i < lensa; ++i)
    {
        if (sa[i] == 1)
            ans = (ans + 1) % p;
        ll y = exp(sa[i], p - 2, p);
        int it = lower_bound(sb, sb + lensb2, y) - sb;
        if (it < lensb2 && sb[it] == y)
            ans = (ans + num[it]) % p;
    }
    cout << ans;

    return 0;
}
