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
    set<int> st;
    cin >> n >> l;
    vector<pair<int, int>> data;
    for (int j = 1; j <= n; ++j){
        cin >> x >> i;
        data.push_back({i,x});
    }
    sort(data.begin(), data.end());
    st.insert(0);
    st.insert(l);
    ll ans = 0;
    for(auto a:data){
        st.insert(a.second);
        auto it = st.lower_bound(a.second);
        ans += (*next(it)) - (*prev(it));
    }
    cout << ans;
    return 0;
}
