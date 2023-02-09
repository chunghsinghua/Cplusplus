#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int p = 1000000007;

struct mat
{
    ll a[2][2];
    mat()
    {
        memset(a, 0, sizeof(a));
    }
    mat operator*(const mat &b) const
    {
        mat ret;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * b.a[k][j]) % p;

        return ret;
    }
};

void solve(int n)
{
    mat ret, f;
    ret.a[0][0] = 1, ret.a[1][0] = 0;
    f.a[0][0] = 1, f.a[0][1] = 1, f.a[1][0] = 1, f.a[1][1] = 0;
    while (n)
    {
        if (n & 1)
            ret = f * ret;
        n >>= 1;
        f = f * f;
    }
    cout << ret.a[0][0] << "\n";
}

int main()
{
    // freopen("P_4_13_4.in", "r", stdin);
    int n;
    while (cin >> n)
    {
        if (n == -1)
            break;
        solve(n - 1);
    }
    return 0;
}
