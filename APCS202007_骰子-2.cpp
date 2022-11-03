#include <bits/stdc++.h>

using namespace std;

#define N 30
typedef long long ll;

int mat[N][6];

int main()
{
    // freopen("P_6_19_5.in", "r", stdin);
    int d[6] = {1, 4, 2, 6, 3, 5}; // top0, front1, right2, bottom3, back4, left5
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 6; ++j)
            mat[i][j] = d[j];
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (b == -1)
        {
            int t = mat[a][0];
            mat[a][0] = mat[a][4];
            mat[a][4] = mat[a][3];
            mat[a][3] = mat[a][1];
            mat[a][1] = t;
        }
        else if (b == -2)
        {
            int t = mat[a][0];
            mat[a][0] = mat[a][5];
            mat[a][5] = mat[a][3];
            mat[a][3] = mat[a][2];
            mat[a][2] = t;
        }
        else
        {
            swap(mat[a], mat[b]);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << mat[i][0] << ' ';
    return 0;
}
