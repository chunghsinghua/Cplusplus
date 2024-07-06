#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

void subset(vector<int> curr, vector<int> &a, int n)
{
    if (n >= a.size())
    {
        if (curr.size() == 0)
            cout << "empty\n";
        else
        {
            for (int e : curr)
                cout << e << ' ';
            cout << '\n';
        }
        return;
    }
    subset(curr, a, n + 1);
    curr.push_back(a[n]);
    subset(curr, a, n + 1);
    return;
}

int main()
{
    // freopen("P_5_4_3.in", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    vector<int> a({4, 1, 5, 8}), curr;
    subset(curr, a, 0);
    return 0;
}
