#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

pair<int, int> d[N];
deque<int> mxq, mnq;

void putmx(int i)
{
    while (!mxq.empty() && d[mxq.back()].second <= d[i].second)
        mxq.pop_back();
    mxq.push_back(i);
}
void putmn(int i)
{
    while (!mnq.empty() && d[mnq.back()].second >= d[i].second)
        mnq.pop_back();
    mnq.push_back(i);
}

int main()
{
    freopen("Q_3_13_3.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
        cin >> d[i].first;
    for (int i = 0; i < n; ++i)
        cin >> d[i].second;
    sort(d, d + n);
    int mx = 0;
    for (int i = 0; i < n; ++i)
    {
        while (!mxq.empty() && d[i].first - d[mxq.front()].first > l)
            mxq.pop_front();
        while (!mnq.empty() && d[i].first - d[mnq.front()].first > l)
            mnq.pop_front();

        putmx(i);
        putmn(i);

        mx = max(mx, d[mxq.front()].second - d[mnq.front()].second);
    }
    cout << mx;
    return 0;
}
