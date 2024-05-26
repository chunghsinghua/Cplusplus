#include <bits/stdc++.h>
using namespace std;

#define N 510
typedef long long ll;

int main()
{
    freopen("Q_3_11_3.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> vec(n), last(n, -1);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    int mx = 0, le = 0;
    for (int i = 0; i < n; ++i)
    {
        int col = vec[i];
        if (last[col] >= le)
            le = last[col] + 1;
        last[col] = i;
        mx = max(mx, i - le + 1);
    }
    cout << mx;
    return 0;
}
