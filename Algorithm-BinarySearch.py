# binary search x between a[left..right]
def fun(s,le,ri):
    while le<=ri:
        mid = (le+ri)//2
        if a[mid]==s:
            return mid
        if a[mid]<s:
            le = mid+1
        else:
            ri = mid-1
    return -1
