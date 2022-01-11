#include <bits/stdc++.h>
using namespace std;
#define N 60000
int d[N];
int n, L;
long long cut(int left, int right){
    if(right-left <= 1)
        return 0;
    long long len = d[right]-d[left];
    int k = (d[left]+d[right])/2;
    int _start = left, _end = right;
    int m;
    while(_start <= _end){  //找出>= k 之index
        int mid = (_start + _end) / 2;
        if(d[mid] == k){
            m = mid;
            break;
        }
        if(d[mid] > k)
            _end = mid - 1;
        else
            _start = mid + 1;
        m = _start;
    }
    if(d[m-1]-d[left] >= d[right]-d[m])
        m--;
        return len + cut(left, m) + cut(m, right);
}
int main() {
    freopen("P_1_3_3.in", "r", stdin);
    cin >> n >> L;
    for(int i = 1; i <= n; ++i)
        cin >> d[i];
    d[0] = 0;
    d[n+1] = L;
    cout << cut(0,n+1);
    return 0;
}
