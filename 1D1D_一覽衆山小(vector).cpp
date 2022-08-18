#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int main()
{
    freopen("P_6_15_4.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> last;
    int t;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        auto it = lower_bound(last.begin(), last.end(), t);
        if (it == last.end())
            last.push_back(t);
        else
            *it = t;
    }
    cout << last.size();
    return 0;
}
