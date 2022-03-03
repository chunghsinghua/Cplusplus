#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int d[N];
int fun(int k, int n)
{
    if (k >= n)
        return 1;
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        bool check = true;
        for (int j = 0; j < k; ++j)
        {
            if (d[j] == i || k - j == abs(d[j] - i))
            {
                check = false;
                break;
            }
        }
        if (!check)
            continue;
        d[k] = i;
        total += fun(k + 1, n);
    }
    return total;
}

int main()
{
    // freopen("q_1_5_5.in", "r", stdin);
    for (int i = 2; i <= 14; ++i)
        cout << fun(0, i) << "\n";
    return 0;
}
