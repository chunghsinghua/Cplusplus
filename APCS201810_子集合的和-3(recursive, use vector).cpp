#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int mx = 0;
void fun(int idx, int sum, vector<int> &vec, int n, int p)
{
    if (idx >= n)
    {
        if (sum <= p)
            mx = max(mx, sum);
        return;
    }
    fun(idx + 1, sum, vec, n, p);
    fun(idx + 1, sum + vec[idx], vec, n, p);
}

int main()
{
    freopen("q_1_8_5.in", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n, p;
    cin >> n >> p;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    fun(0, 0, vec, n, p);
    cout << mx;
    return 0;
}
