#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int main()
{
    freopen("P_4_2_2.in", "r", stdin);
    int n;
    cin >> n;
    int me[N], enemy[N];
    for (int i = 0; i < n; ++i)
        cin >> enemy[i];
    for (int i = 0; i < n; ++i)
        cin >> me[i];
    sort(enemy, enemy + n, greater<int>());
    sort(me, me + n, greater<int>());
    int cnt = 0;
    for (int i = 0, idx = 0; i < n; ++i)
    {
        while (idx < n && enemy[idx] >= me[i])
            idx++;
        if (idx >= n)
            break;
        cnt++;
        idx++;
    }
    cout << cnt;
    return 0;
}
