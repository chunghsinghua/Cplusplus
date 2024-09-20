#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_4_11_5.in", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> vec(n + 1, 0);
    vec[n - k] = 0;
    for (int i = n - k + 1; i <= n; ++i)
        vec[i] = (vec[i - 1] + m) % i;
    cout << vec[n] + 1;
    return 0;
}
