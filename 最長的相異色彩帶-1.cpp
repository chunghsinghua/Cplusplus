#include <bits/stdc++.h>
using namespace std;

#define N 510
typedef long long ll;

int main()
{
    freopen("Q_3_11_5.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> vec(n), color(n + 1);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    int cnt = 0;
    for (int le = 0, ri = 0; ri < n; ++ri)
    {
        color[vec[ri]]++;
        while (color[vec[ri]] > 1)
        {
            color[vec[le]]--;
            le++;
        }
        cnt = max(cnt, ri - le + 1);
    }
    cout << cnt;
    return 0;
}
