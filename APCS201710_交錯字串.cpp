#include <bits/stdc++.h>
using namespace std;

#define N 200010
typedef long long ll;

int d[N];

int main()
{
    // freopen("P_2_2_4.in", "r", stdin);
    string s;
    int k;
    cin >> k;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; ++i)
    {
        if (isupper(s[i]))
            s[i] = '0';
        else
            s[i] = '1';
    }
    vector<int> b;
    int cnt = 1;
    for (int i = 1; i < len; ++i)
    {
        if (s[i] == s[i - 1])
            cnt++;
        else
        {
            b.push_back(cnt);
            cnt = 1;
        }
    }
    b.push_back(cnt);
    int left = 0, right, ans = 0;
    int blen = b.size();
    while (left < blen)
    {
        int temp = 0;
        while (left < b.size() && b[left] != k)
            left++;
        if (left >= blen)
            break;
        right = left + 1;
        while (right < blen && b[right] == k)
            right++;
        temp = (right - left) * k;
        if (right < blen && b[right] > k)
            temp += k;
        if (left != 0 && b[left - 1] > k)
            temp += k;
        ans = max(ans, temp);
        left = right + 1;
    }
    cout << ans;
    return 0;
}
