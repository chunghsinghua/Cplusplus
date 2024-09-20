#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

ll fun(int p)
{
    int child = 2 + (p % 2);
    ll ret = 0;
    for (int i = 0; i < child; ++i)
    {
        int t;
        cin >> t;
        if (t == 0)
            continue;
        ret += abs(p - t);
        ret += fun(t);
    }
    return ret;
}

int main()
{
    int v;
    cin >> v;
    cout << fun(v);
    return 0;
}
