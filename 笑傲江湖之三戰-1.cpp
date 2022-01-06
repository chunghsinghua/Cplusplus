#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int me[N], enemy[N];

int main()
{
    freopen("P_4_2_4.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> enemy[i];
    for (int i = 0; i < n; ++i)
        cin >> me[i];
    sort(me, me + n);
    sort(enemy, enemy + n);
    int ans = 0;
    for (int i = 0, j = 0; i < n; ++i)
    {
        if (me[i] > enemy[j])
        {
            ans++;
            j++;
        }
    }
    cout << ans;
    return 0;
}
