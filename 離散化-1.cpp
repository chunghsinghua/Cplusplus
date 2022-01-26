#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int d[N], refer[N];

int fun(int n, int from[], int to[])
{
    vector<int> temp(from, from + n);
    sort(temp.begin(), temp.end());
    int idx = 1;
    to[0] = temp[0];
    for (int i = 1; i < temp.size(); ++i)
    {
        if (temp[i] != temp[i - 1])
            to[idx++] = temp[i];
    }
    return idx;
}

int main()
{
    freopen("P_2_2_2.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    int total = fun(n, d, refer);
    for (int i = 0; i < n; ++i)
        d[i] = lower_bound(refer, refer + total, d[i]) - refer;
    for (int i = 0; i < n; ++i)
        cout << d[i] << " ";
    return 0;
}
