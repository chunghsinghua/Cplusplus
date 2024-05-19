#include <bits/stdc++.h>
using namespace std;

#define N 510
typedef long long ll;

int main()
{
    freopen("Q_3_11_3.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> vec(n), last(n + 1, -1);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    int cnt = 0, le = 0;
    for (int i = 0; i < n; ++i)
    {
        if (last[vec[i]] >= le)
            le = last[vec[i]] + 1;
        last[vec[i]] = i;
        cnt = max(cnt, i - le + 1);
    }
    cout << cnt;
    return 0;
}
