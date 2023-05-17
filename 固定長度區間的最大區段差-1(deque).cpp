#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N];
deque<int> maxq, minq;

void putmx(int i)
{
    while (!maxq.empty() && d[maxq.back()] <= d[i])
        maxq.pop_back();
    maxq.push_back(i);
}
void putmn(int i)
{
    while (!minq.empty() && d[minq.back()] >= d[i])
        minq.pop_back();
    minq.push_back(i);
}

int main()
{
    // freopen("P_3_8_5.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    int ans = 0;
    maxq.push_back(0);
    minq.push_back(0);
    for (int i = 1; i < n; ++i)
    {
        if (maxq.front() <= i - l)
            maxq.pop_front();
        if (minq.front() <= i - l)
            minq.pop_front();
        putmn(i), putmx(i);
        int diff = d[maxq.front()] - d[minq.front()];
        ans = max(diff, ans);
    }
    cout << ans;
    return 0;
}
