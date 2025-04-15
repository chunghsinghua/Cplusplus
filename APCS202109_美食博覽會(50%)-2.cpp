#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n), last(n, -1);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    int mx = 0, le = 0;
    for (int i = 0; i < n; ++i)
    {
        if (last[vec[i]] >= le)
            le = last[vec[i]] + 1;
        last[vec[i]] = i;
        mx = max(mx, i - le + 1);
    }
    cout << mx;
    return 0;
}
