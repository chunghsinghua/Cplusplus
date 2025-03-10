#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

bool fun(vector<int> &h, vector<int> &w, int hi)
{
    int wi = 0;
    int wcnt = 0;
    for (int e : h)
    {
        if (e < hi)
            wcnt = 0;
        else
        {
            wcnt++;
            if (wcnt == w[wi])
            {
                wi++;
                wcnt = 0;
            }
            if (wi == w.size())
                return true;
        }
    }
    return false;
}

int main()
{
    // freopen("P_5_4_1.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> h(n), w(k);
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    for (int i = 0; i < k; ++i)
        cin >> w[i];
    int best = 0;
    for (int jump = 1e9 / 2; jump > 0; jump >>= 1)
    {
        while (fun(h, w, best + jump))
            best += jump;
    }
    cout << best;

    return 0;
}
