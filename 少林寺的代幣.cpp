#include <bits/stdc++.h>

using namespace std;

#define N 100010
#define M 50010
typedef long long ll;

int main()
{
    freopen("P_4_1.in", "r", stdin);
    int coins[4] = {50, 10, 5, 1};
    int n;
    cin >> n;
    int t, total;
    while (n--)
    {
        total = 0;
        cin >> t;
        for (int i = 0; i < 4; ++i)
        {
            total += t / coins[i];
            t = t % coins[i];
        }
        cout << total << "\n";
    }
    return 0;
}
