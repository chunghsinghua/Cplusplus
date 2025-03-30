#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_6_15_3.in", "r", stdin);
    vector<int> vec;
    int t;
    string s, pattern = " ";
    getline(cin, s);
    int st = 0, en = s.find(pattern);
    while (en != string::npos)
    {
        vec.push_back(stoi(s.substr(st, en - st)));
        st = en + pattern.size();
        en = s.find(pattern, st);
    }
    stack<pair<int, int>> stk; // value, deg
    stk.push({vec[0], 0});     // dummy
    ll diff = 0;
    for (int e : vec)
    {
        if (e > 0)
        {
            diff += abs(stk.top().first - e);
            stk.push({e, 2 + e % 2});
        }
        else
        {
            stk.top().second -= 1;
            while (stk.top().second == 0)
            {
                stk.pop();
                stk.top().second -= 1;
            }
        }
    }
    cout << diff;
    return 0;
}
