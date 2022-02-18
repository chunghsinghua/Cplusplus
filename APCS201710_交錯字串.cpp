#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int d[N];

int main()
{
    // freopen("p_1_7_3.in", "r", stdin);
    int k;
    string s;
    cin >> k;
    cin >> s;
    int slen = s.size();
    for (int i = 0; i < slen; ++i)
    {
        if (islower(s[i]))
            s[i] = '0';
        else
            s[i] = '1';
    }
    int cnt = 1;
    vector<int> b;
    for (int i = 1; i < slen; ++i)
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
        }
        else
        {
            b.push_back(cnt);
            cnt = 1;
        }
    }
    b.push_back(cnt);
    int blen = b.size();
    int left = 0, right, ans = 0;
    while (left < blen)
    {
        while (left < blen && b[left] != k)
            left++;
        if (left >= blen)
            break;
        right = left + 1;
        while (right < blen && b[right] == k)
            right++;
        int temp = (right - left) * k;
        if (left > 0 && b[left - 1] > k)
            temp += k;
        if (right < blen && b[right] > k)
            temp += k;
        ans = max(ans, temp);
        left = right + 1;
    }
    cout << ans;
    return 0;
}
