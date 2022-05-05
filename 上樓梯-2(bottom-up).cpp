#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

ll ftable[N];

int main()
{
    // freopen("P_4_15_1.in", "r", stdin);
    int n;
    cin >> n;
    ftable[1] = 1, ftable[2] = 2;
    for (int i = 3; i <= n; ++i)
        ftable[i] = ftable[i - 1] + ftable[i - 2];

    cout << ftable[n];
    return 0;
}
