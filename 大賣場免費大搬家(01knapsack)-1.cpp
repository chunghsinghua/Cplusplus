#include <bits/stdc++.h>
using namespace std;

#define N 110
#define W 100010
typedef long long ll;

int dp[N][W];
int wei[N],p[N];

int main()
{
    freopen("P_6_9_5.in", "r", stdin);
    int n,w;
    cin>>n>>w;
    for(int i = 1;i<=n; ++i)
        cin>>wei[i];
    for(int i = 1;i<=n; ++i)
        cin>>p[i];

    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<wei[i]; ++j)
            dp[i][j] = dp[i-1][j];
        for(int j = wei[i]; j<=w; ++j)
            dp[i][j]=max(dp[i-1][j],p[i]+dp[i-1][j-wei[i]]);
    }
    cout << dp[n][w];

    return 0;
}
