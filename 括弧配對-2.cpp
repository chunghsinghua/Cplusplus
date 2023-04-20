#include <bits/stdc++.h>
using namespace std;

#define N 210
typedef long long ll;

int mat[N][N];

int main()
{
    freopen("P_3_2_5.in", "r", stdin);
    string s;
    string ref = "([{)]}";
    while (cin >> s)
    {
        int len = s.size();
        stack<int> stk;
        bool check = true;
        for (int i = 0; i < len; ++i)
        {
            int ob = ref.find(s[i]);
            if (ob <= 2)
                stk.push(ob);
            else
            {
                if (!stk.empty() && stk.top() + 3 == ob)
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
