#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int parent[N], height[N];

int main()
{
    freopen("P_3_1_3.in", "r", stdin);
    int n, t;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int childnum;
        cin >> childnum;
        for (int j = 0; j < childnum; ++j)
        {
            cin >> t;
            parent[t] = i;
        }
    }
    int root;
    for (int i = 1; i <= n; ++i)
        if (parent[i] == 0)
        {
            root = i;
            break;
        }

    cout << root << "\n";
    for (int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        for (int j = i; j != 0; j = parent[j])
        {
            height[j] = max(height[j], cnt);
            cnt++;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += height[i];
    cout << sum;
    return 0;
}
