#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int d[N];
int n, m;

int enough(int energy)
{
    int times = m, e = energy;
    for (int i = 0; i < n; ++i)
    {
        if (e < d[i])
        {
            if (times)
            {
                times--;
                e = energy;
            }
            else
                return false;
        }
        e -= d[i];
    }
    return true;
}

int main()
{
    freopen("Q_4_10_5.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    int f = 0, len = 1e9;
    for (int jump = len / 2; jump > 0; jump >>= 1)
        while (f + jump < len && !enough(f + jump))
            f += jump;
    cout << f + 1;
    return 0;
}
