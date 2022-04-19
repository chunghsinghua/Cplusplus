#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

ll ftable[N];

ll fun(int n)
{
    if (n <= 2)
        return n;
    return fun(n - 1) + fun(n - 2);
}

int main()
{
    // freopen("P_4_15_1.in", "r", stdin);
    int n;
    cin >> n;
    cout << fun(n);
    return 0;
}
