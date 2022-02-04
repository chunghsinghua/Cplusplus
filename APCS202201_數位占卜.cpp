#include <bits/stdc++.h>
using namespace std;

#define N 50010

string s[N];

int main()
{
    // freopen("P_3_9_5.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    set<string> sset;
    for (int i = 0;i<m; ++i)
    {
        cin >> s[i];
        sset.insert(s[i]);
    }
    int ans = 0;
    string astr;
    for (int i = 0;i<m; ++i){
        astr = s[i];
        int len = astr.size();
        if(len<=2)
            continue;
        for (int j = 1; j <= len / 2; ++j){
            if(astr.substr(0,j)==astr.substr(len-j,j))
                if(sset.count(astr.substr(j,len-j-j)))
                    ans++;
        }
    }
    cout << ans;
    return 0;
}
