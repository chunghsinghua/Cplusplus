#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int d[N];
int n, m;

bool fun(int e)
{
    int times = m, energy = e;
    for (int i = 0; i < n; ++i)
    {
        if (energy < d[i])
        {
            if (times)
            {
                times--;
                energy = e;
            }
            else
                return false;
        }
        energy -= d[i];
    }
    return true;
}

int main()
{
    freopen("Q_4_10_2.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    int low = 1, up = 1e9;
    while (low < up)
    {
        int m = (low + up) >> 1;
        if (fun(m))
            up = m;
        else
            low = m + 1;
    }
    cout << low;
    return 0;
}
