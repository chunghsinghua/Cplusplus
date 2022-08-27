
#include <bits/stdc++.h>
using namespace std;
#define N 50010
typedef long long ll;
int d[N], check[N];
int main()
{
    // freopen("P_2_9_1.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (check[i] == 0)
        {
            int current = i;
            int start = i;
            while (d[start] != current)
            {
                start = d[start];
                check[start] = 1;
            }
            check[i] = 1;
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
