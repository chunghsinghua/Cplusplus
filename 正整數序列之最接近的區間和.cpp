#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_3_7_4.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    int cnt = 0, sum = 0, ans = 0;
    for (int left = 0, right = 0; right < n; ++right)
    {
        sum += d[right];
        while (sum > k)
        {
            sum -= d[left++];
        }
        if (sum > ans)
        {
            ans = sum;
            cnt = 1;
        }
        else if (sum == ans)
            cnt++;
    }
    cout << ans << "\n"
         << cnt;
    return 0;
}
