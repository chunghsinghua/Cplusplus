#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

struct act
{
    int s, t;
};
bool cmp(act a, act b)
{
    return a.t < b.t;
}

act d[N];

int main()
{
    freopen("P_4_4_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> d[i].s >> d[i].t;
    }
    sort(d, d + n, cmp);
    int endtime = -1;
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        if (d[i].s > endtime)
        {
            total++;
            endtime = d[i].t;
        }
    }
    cout << total;
    return 0;
}
