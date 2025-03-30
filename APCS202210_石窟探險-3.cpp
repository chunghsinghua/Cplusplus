#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int idx;
ll fun(int v, vector<int> &vec)
{
    ll ret = 0;
    for (int i = 0; i < 2 + v % 2; ++i)
    {
        int u = vec[idx];
        idx++;
        if (u > 0)
            ret += abs(v - u) + fun(u, vec);
    }
    return ret;
}

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
    idx = 1;
    cout << fun(vec[0], vec);
    return 0;
}
