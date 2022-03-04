#include <bits/stdc++.h>

using namespace std;

#define N 100000010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_4_11_1.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int s, t;
    for (int i = 0; i < n; ++i)
    {
        cin >> s >> t;
        for (int j = s; j < t; ++j)
            d[j]++;
    }
    int sum = 0;
    for (int i = 0; i < N; ++i)
        sum += (d[i] != 0);

    cout << sum;
    return 0;
}
