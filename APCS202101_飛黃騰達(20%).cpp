#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int fun(int n, int m, int k)
{
    if (k == 0)
        return 0;
    return (fun(n - 1, m, k - 1) + m) % n;
}

int main()
{
    // freopen("P_3_8_5.in", "r", stdin);
    int n, x, y;
    cin >> n;
    vector<vector<int>> mat(101, vector<int>(101, 0));
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        mat[x][y] = 1;
    }
    for (int i = 1; i <= 100; ++i)
    {
        for (int j = 1; j <= 100; ++j)
            mat[i][j] += max(mat[i - 1][j], mat[i][j - 1]);
    }
    cout << mat[100][100];
    return 0;
}
