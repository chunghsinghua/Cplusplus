#include <bits/stdc++.h>

using namespace std;

#define N 11
typedef long long ll;

int a[N][N], b[N][N];

int main()
{
    // freopen("q_1_5_5.in", "r", stdin);
    int r, c, m;
    while (cin >> r >> c >> m)
    {
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> a[i][j];
        vector<int> op;
        for (int i = 0; i < m; ++i)
        {
            int temp;
            cin >> temp;
            op.push_back(temp);
        }
        reverse(op.begin(), op.end());
        for (int k = 0; k < m; ++k)
        {
            if (op[k] == 1)
            {
                for (int i = 0; i < r / 2; ++i)
                    swap(a[i], a[r - 1 - i]);
            }
            else if (op[k] == 0)
            {
                memcpy(b, a, sizeof(a));
                swap(r, c);
                for (int i = 0; i < r; ++i)
                {
                    for (int j = 0; j < c; ++j)
                    {
                        a[i][j] = b[j][r - 1 - i];
                    }
                }
            }
        }
        cout << r << " " << c << "\n";
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c - 1; ++j)
                cout << a[i][j] << " ";
            cout << a[i][c - 1] << "\n";
        }
    }
    return 0;
}
