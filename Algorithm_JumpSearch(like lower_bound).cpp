// binary search the first >=x between a[0..n-1]
int jumpsearch(int a[], int n, int x)
{
    if (a[0] >= x)
        return 0;
  
    int pos = 0;
    for (int jump = n / 2; jump > 0; jump >>= 1)
        while (pos + jump < n && a[pos + jump] < x)
            pos += jump;
  
    return pos + 1;
}
