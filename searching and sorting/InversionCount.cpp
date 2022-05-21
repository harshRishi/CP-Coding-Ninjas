typedef long long ll;
ll merge(ll *a, int si, int mid, int ei)
{
    ll count = 0;

    int i = si, j = mid, fillerIndex = 0;
    ll temp[ei - si + 1];

    while (i < mid && j <= ei)
    {
        if (a[i] <= a[j])
            temp[fillerIndex++] = a[i++]; // ith element is samller
        else
        {
            temp[fillerIndex++] = a[j++]; // jth element is smaller
            count += mid - i;             // ie length of the first half as "a" is sorted so elemrnt on the right of a[] will be greater than a[j] so total inversion count with be length of fisrt half from i to mid - 1
        }
    }
    // filler the rest a[i] || a[j]
    while (i < mid)
        temp[fillerIndex++] = a[i++];
    while (j <= ei)
        temp[fillerIndex++] = a[j++];

    for (int i = si, k = 0; i <= ei; i++, k++) // copy the merged temp arr to a[k]
    {
        a[i] = temp[k];
    }
    return count;
}

ll merge_sort(ll *arr, int si, int ei)
{
    ll count = 0; // this will be returned if we didnt get ei > si
    if (ei > si)  // base case
    {
        int mid = ((si + ei) / 2);
        ll firstCount = merge_sort(arr, si, mid);
        ll secondCount = merge_sort(arr, mid + 1, ei);
        ll mergeCount = merge(arr, si, mid + 1, ei); // mid +1 is starting index of the 2nd half

        return mergeCount + firstCount + secondCount; // dono half ka count plus merge a inversion count
    }
    return count;
}

long long getInversions(long long *arr, int n)
{
    // Edge case
    if (n == 0 || n == 1)
        return 0;
    return merge_sort(arr, 0, n - 1);
}