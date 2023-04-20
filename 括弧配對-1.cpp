#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int d[N];

int main()
{
    freopen("P_3_2_5.in", "r", stdin);
    string s;
    string refer = "([{)]}";
    bool check;

    while (cin >> s)
    {
        int len = s.size();
        stack<char> stk;
        check = true;

        for (int i = 0; i < len; ++i)
        {
            if (refer.find(s[i]) < 3)
                stk.push(s[i]);
            else
            {
                if (!stk.empty() && refer.find(s[i]) - 3 == refer.find(stk.top()))
                    stk.pop();
                else
                {
                    check = false;
                    break;
                }
            }
        }
        if (!stk.empty())
            check = false;

        if (check)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
