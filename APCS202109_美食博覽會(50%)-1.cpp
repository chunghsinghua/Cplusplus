#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    vector<int> d(1e5 + 1, 0);
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    int mx = 0;
    for (int le = 0, ri = 0; ri < n; ++ri)
    {
        int num = vec[ri];
        d[num]++;
        while (d[num] >= 2)
        {
            d[vec[le]]--;
            le++;
        }
        mx = max(mx, ri - le + 1);
    }
    cout << mx;
    return 0;
}
