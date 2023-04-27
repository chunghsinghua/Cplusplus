#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int d[N];
bool visit[N];

int main()
{
    // freopen("Q_6_4_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (visit[i])
            continue;
        visit[i] = true;
        int s = d[i];
        while (s != i)
        {
            visit[s] = true;
            s = d[s];
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}
