#include <bits/stdc++.h>
using namespace std;

#define N 15
typedef long long ll;

int mat[N][N], refer[N][N], op[N];
int r, c, m;

void flip(int r, int c)
{
    for (int ri = 0; ri < r / 2; ++ri)
        swap(mat[ri], mat[r - 1 - ri]);
}
void rotate(int r, int c)
{
    swap(r, c);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            refer[i][j] = mat[j][r - 1 - i];
    swap(mat, refer);
}

int main()
{
    // freopen("P_8_14_5.in", "r", stdin);
    while (cin >> r >> c >> m)
    {
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> mat[i][j];
        for (int i = 0; i < m; ++i)
            cin >> op[i];
        for (int i = m - 1; i >= 0; --i)
        {
            if (op[i] == 0)
            {
                rotate(r, c);
                swap(r, c);
            }
            if (op[i] == 1)
                flip(r, c);
        }
        cout << r << ' ' << c << '\n';
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                cout << mat[i][j];
                if (j < c - 1)
                    cout << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
