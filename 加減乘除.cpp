#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;
int h[N];
vector<int> child[N];
int parent[N];

int main()
{
    freopen("Q_3_3_5.in", "r", stdin);
    string s;
    cin >> s;
    stack<char> ops;
    stack<int> nums;
    nums.push(s[0] - '0');
    int ctemp;
    for (int i = 1; i < s.size(); i += 2)
    {
        char op = s[i];
        int num = s[i + 1] - '0';
        if (op == '*' || op == '/')
        {
            int prenum = nums.top();
            nums.pop();
            if (op == '*')
                ctemp = prenum * num;
            else
                ctemp = prenum / num;

            nums.push(ctemp);
        }
        else
        {
            if (!ops.empty())
            {
                int n2 = nums.top();
                nums.pop();
                int n1 = nums.top();
                nums.pop();
                char op1 = ops.top();
                if (op1 == '+')
                    n1 += n2;
                else
                    n1 -= n2;
                nums.push(n1);
            }
            nums.push(num);
            ops.push(op);
        }
    }
    int ans = 0;
    if (!ops.empty())
    {
        int n2 = nums.top();
        nums.pop();
        // cout << n2 << "\n";
        char op1 = ops.top();
        ops.pop();
        // cout << op1 << "\n";

        ans = nums.top();
        // cout << ans << "\n";

        if (op1 == '+')
            ans += n2;
        else
            ans -= n2;
    }
    else
    {
        ans = nums.top();
    }

    cout << ans;
    return 0;
}
