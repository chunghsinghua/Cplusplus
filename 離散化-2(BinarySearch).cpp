#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_2_2_1.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    vector<int> temp(d, d + n);
    sort(temp.begin(), temp.end());
    vector<int> to;
    to.push_back(temp.front());
    for (int i = 1; i < temp.size(); ++i)
    {
        if (temp[i] != temp[i - 1])
            to.push_back(temp[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        if (d[i] == to[0])
        {
            d[i] = 0;
            continue;
        }
        int po = 0;
        for (int jump = to.size() / 2; jump > 0; jump >>= 1)
            while (po + jump < to.size() && to[po + jump] < d[i])
                po += jump;
        d[i] = po + 1;
    }
    for (int i = 0; i < n; ++i)
        cout << d[i] << " ";
    return 0;
}
