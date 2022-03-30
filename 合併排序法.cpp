#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int d[N];

void msort(int a[], int le, int ri)
{
    if (le + 1 >= ri)
        return;
    int m = (le + ri) >> 1;
    msort(a, le, m), msort(a, m, ri);
    int temp[ri - le];
    int j = m, k = 0;
    for (int i = le; i < m; ++i)
    {
        while (j < ri && a[j] < a[i])
            temp[k++] = a[j++];
        temp[k++] = a[i];
    }

    for (k = le; k < j; ++k)
        a[k] = temp[k - le];

    return;
}
int main()
{
    // freopen("P_5_4_2.in", "r", stdin);
    srand(time(0));
    int n = 20;
    for (int i = 0; i < n; ++i)
        d[i] = rand() % 100;
    for (int i = 0; i < n; ++i)
        cout << d[i] << " ";
    cout << "\n";
    msort(d, 0, n);
    for (int i = 0; i < n; ++i)
        cout << d[i] << " ";
    cout << "\n";
    return 0;
}
