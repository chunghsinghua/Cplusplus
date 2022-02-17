#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int d[N];

int main()
{
    freopen("p_1_7_5.in", "r", stdin);
    int n;
    int p = 10009;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    int cnt = 0;
    for (int i = 1; i < (1 << n); ++i)
    {
        ll prod = 1;
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                prod = prod * d[j] % p;
            }
        }
        if (prod == 1)
            cnt++;
    }
    cout << cnt;
    return 0;
}
