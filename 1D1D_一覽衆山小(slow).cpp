#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int last[N];

int main()
{
    freopen("P_6_15_5.in", "r", stdin);
    int n;
    cin >> n;
    int len = 0;
    int t;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        int r = 0;
        while (r < len && last[r] < t)
            r++;
        last[r] = t;
        if (r == len)
            len++;
    }
    cout << len;
    return 0;
}
