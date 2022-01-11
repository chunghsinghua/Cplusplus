#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int d[N];

ll cut(int left, int right)
{
    if (left + 1 >= right)
        return 0;
    ll cost = d[right] - d[left];
    int mid = (d[left] + d[right]) / 2;
    int m = left;
    for (int jump = (right - left) / 2; jump > 0; jump /= 2)
    {
        while (m + jump < right && d[m + jump] < mid)
            m += jump;
    }
    if (d[m] - d[left] < d[right] - d[m + 1])
        m++;
    return cost + cut(left, m) + cut(m, right);
}

int main()
{
    freopen("p_1_3_3.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    d[0] = 0, d[n + 1] = l;
    cout << cut(0, n + 1);
    return 0;
}
