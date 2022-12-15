int bsearch(int a[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (a[mid] == x)
            return mid;
        if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
