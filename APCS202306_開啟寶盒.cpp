#include <bits/stdc++.h>

using namespace std;

#define N 510
typedef long long ll;

int main()
{
    // freopen("Q_7_8_2.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n, k, t, T;
    cin >> n >> m >> k;
    cin >> T;
    vector<int> mykey;
    vector<bool> keycheck(m, false);
    for (int i = 0; i < T; ++i)
    {
        cin >> t;
        mykey.push_back(t);
        keycheck[t] = true;
    }
    vector<vector<int>> keytobox(m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            cin >> t;
            keytobox[t].push_back(i);
        }
    }
    vector<vector<int>> boxkey(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j)
        {
            cin >> t;
            boxkey[i].push_back(t);
        }
    vector<int> dag(n, k);
    int cnt = 0;
    while (!mykey.empty())
    {
        int key = mykey.back();
        mykey.pop_back();
        for (int box : keytobox[key])
        {
            dag[box]--;
            if (dag[box] == 0)
            {
                cnt++;
                for (int getkey : boxkey[box])
                {
                    if (keycheck[getkey])
                        continue;
                    mykey.push_back(getkey);
                    keycheck[getkey] = true;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
