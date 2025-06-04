#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int idx = 0;
string s;
ll addmul();
ll fun();
ll addmul()
{
    vector<ll> stk;
    ll num;
    char op;
    int len = s.size();
    while ((idx < len) && (s[idx] != ',') && (s[idx] != ')'))
    {
        if (s[idx] == '+' || s[idx] == '*')
        {
            op = s[idx++];
            continue;
        }
        else if (s[idx] == 'f')
        {
            idx += 2;
            num = fun();
        }
        else
        {
            int j = idx;
            while (j < len && isdigit(s[j]))
                j++;
            num = stoll(s.substr(idx, j - idx));
            idx = j;
        }
        if (op == '+')
            stk.back() += num;
        else
            stk.push_back(num);
    }

    ll ret = 1;
    while (!stk.empty())
    {
        ret *= stk.back();
        stk.pop_back();
    }
    return ret;
}

ll fun()
{
    ll mn = addmul();
    ll mx = mn;
    ll num;
    while ((idx < s.size()) && (s[idx] != ')'))
    {
        idx++;
        num = addmul();
        // cout << endl;
        mn = min(mn, num);
        mx = max(mx, num);
    }
    idx++;
    // cout << mx - mn << endl;
    return mx - mn;
}
int main()
{
    // freopen("P_7_12_3.in", "r", stdin);
    cin >> s;
    cout << addmul();
    return 0;
}
