#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    long count = 0;
    int i = 0, j = 1;
    while (j < n)
    {
        if (arr[j] - arr[i] >= k) // incase we found the pair at jth, and as arr is sort so from jth index to n every element can pair with ith element
        {
            count += (n - j);
            i++;
        }
        else
            j++;
    }
    cout << count << endl;
    return 0;
}

/*
3 1
3 1 3
*/