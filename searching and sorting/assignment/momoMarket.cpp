#include <bits/stdc++.h>
using namespace std;
#define int long long

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x || l > r)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
}

signed main()
{
    // write your code
    int n;
    cin >> n;
    int market[n];
    for (int i = 0; i < n; i++)
        cin >> market[i];

    int q;
    cin >> q;

    // create prefix sum arry // O(q*log(n))
    int prefixArr[n];
    prefixArr[0] = market[0];
    for (int i = 1; i < n; i++)
        prefixArr[i] = prefixArr[i - 1] + market[i]; // this is already sorted

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        int index = binarySearch(prefixArr, 0, n - 1, x);
        cout << index + 1 << " " << x - prefixArr[index] << '\n';
    }

    /* O(q*n) Approch
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        int momo = 0, saved = 0;
        for(int i= 0;i<n;i++){
            if(x > 0 && market[i] <= x){
                momo++;
                x -= market[i];
            } else {
                break;
            }
        }
        // print the value of momo and money saved
        cout << momo << " " << x << '\n';
    }
    */
    return 0;
}