#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int d[N];

int main()
{
    // freopen("p_1_7_5.in", "r", stdin);
    for (int k = 2; k <= 11; ++k)
    {
        for (int i = 0; i < k; ++i)
            d[i] = i;
        int ans = 0;
        do
        {
            bool check = true;
            for (int i = 0; i < k; ++i)
            {
                for (int j = i + 1; j < k; ++j)
                {
                    if (j - i == abs(d[j] - d[i]))
                    {
                        check = false;
                        break;
                    }
                }
                if (check == false)
                    break;
            }
            if (check)
                ans++;
        } while (next_permutation(d, d + k));
        cout << ans << "\n";
    }

    return 0;
}
