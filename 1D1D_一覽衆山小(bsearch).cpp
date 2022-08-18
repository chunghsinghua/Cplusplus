#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int last[N];

int main()
{
    freopen("P_6_15_2.in", "r", stdin);
    int n;
    cin >> n;
    int len = 0, t;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        int r = distance(last, lower_bound(last, last + len, t));
        last[r] = t;
        if (r == len)
            len++;
    }
    cout << len;
    return 0;
}
