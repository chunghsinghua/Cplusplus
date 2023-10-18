#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

struct Work
{
    int t, d;
} work[N];

bool cmp(Work &a, Work &b)
{
    if (a.d == b.d)
        return a.t < b.t;
    return a.d < b.d;
}

int main()
{
    freopen("Q_4_17_5.in", "r", stdin);
    int n, k;
    cin >> k;
    while (k--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> work[i].t;
        for (int i = 0; i < n; ++i)
            cin >> work[i].d;
        sort(work, work + n, cmp);
        int time = 0;
        bool check = true;
        for (int i = 0; i < n; ++i)
        {
            time += work[i].t;
            if (time > work[i].d)
            {
                check = false;
                break;
            }
        }
        if (check)
            cout << "yes";
        else
            cout << "no";

        cout << '\n';
    }

    return 0;
}
