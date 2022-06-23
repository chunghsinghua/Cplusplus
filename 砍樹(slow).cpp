#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int c[N], h[N];

int cut(int c[], int h[], int k)
{
    for (int i = 1; i < k - 1; ++i)
        if (c[i] - h[i] >= c[i - 1] || c[i] + h[i] <= c[i + 1])
            return i;
    return -1;
}

int main()
{
    freopen("p_3_6_5.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    c[0] = 0, c[n + 1] = l;
    n += 2;
    int total = 0;
    int high = 0;
    while (1)
    {
        int cutindex = cut(c, h, n);
        if (cutindex < 0)
            break;
        total++;
        high = max(high, h[cutindex]);
        for (int i = cutindex; i < n - 1; ++i)
        {
            c[i] = c[i + 1];
            h[i] = h[i + 1];
        }
        n--;
    }
    cout << total << "\n"
         << high;

    return 0;
}
