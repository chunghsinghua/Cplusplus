#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int d[N];
ll lps[N], rps[N];

int fun(int left, int right, int k)
{
    if (k <= 0)
        return 0;
    if (right - left < 2)
        return 0;
    ll delta = 0;
    lps[left] = 0;
    for (int i = left + 1; i < right; ++i)
    {
        delta += d[i - 1];
        lps[i] = lps[i - 1] + delta;
    }
    delta = 0;
    rps[right] = 0;
    for (int i = right - 1; i > left; --i)
    {
        delta += d[i + 1];
        rps[i] = rps[i + 1] + delta;
    }
    ll check = LLONG_MAX;
    int idx = -1;
    for (int i = left + 1; i < right; ++i)
    {
        ll temp = abs(lps[i] - rps[i]);
        if (temp < check)
        {
            check = temp;
            idx = i;
        }
    }
    return d[idx] + fun(left, idx - 1, k - 1) + fun(idx + 1, right, k - 1);
}

int main()
{
    freopen("Q_1_4_5.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    cout << fun(0, n - 1, k);

    return 0;
}
