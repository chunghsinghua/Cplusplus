#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int main()
{
    // freopen("p_2_3_5.in", "r", stdin);
    string s;
    cin >> s;
    int v = 0;
    for (auto a : s)
        v = v * 10 + (a - '0');

    cout << v + 5; // verify
    return 0;
}
