#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int c[N],h[N];

int main()
{
    // freopen("P_8_14_1.in", "r", stdin);
    int n,l;
    cin>>n>>l;
    for(int i = 1;i<=n; ++i)
        cin>>c[i];
    for(int i = 1;i<=n; ++i)
        cin>>h[i];
    c[n]=l;
    h[0]=h[n+1]=1e9+1;
    stack<int>stk;
    stk.push(0);
    int cnt = 0,mx = 0;
    for(int i = 1;i<=n; ++i){
        if(c[i]-h[i]>=c[stk.top()]||c[i]+h[i]<=c[i+1]){
            cnt++;
            mx = max(mx,h[i]);

            while(!stk.empty() && c[stk.top()]+h[stk.top()]<=c[i+1])
            {
                cnt++;
                mx = max(mx,h[stk.top()]);
                stk.pop();
            }
        }
        else
            stk.push(i);
        
    }
    cout << cnt << '\n'<<mx;
    return 0;
}
