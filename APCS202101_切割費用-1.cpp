#include <bits/stdc++.h>
using namespace std;

#define N 200000
typedef long long ll;

int main()
{
    // freopen("P_3_9_5.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l, x, i;
    set<int> spos,sneg;
    cin >> n >> l;
    vector<pair<int, int>> data;
    for (int j = 1; j <= n; ++j){
        cin >> x >> i;
        data.push_back({i,x});
    }
    sort(data.begin(), data.end());
    spos.insert(0);
    spos.insert(l);
    sneg.insert(0);
    sneg.insert(-l);
    ll ans = 0;
    ll right, left;
    for (int i = 0; i < data.size(); ++i){
        spos.insert(data[i].second);
        sneg.insert(-data[i].second);
        right = *spos.upper_bound(data[i].second);
        left = *sneg.upper_bound(-data[i].second);
        ans+=right+left;
    }
    cout << ans;
    return 0;
}
