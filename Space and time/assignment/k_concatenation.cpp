#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll kadane(int *arr, int n)
{
    ll currSum = 0;
    ll bestSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum > bestSum)
            bestSum = currSum;

        if (currSum < 0)
            currSum = 0;
    }
    return bestSum;
}

ll k_concatenation(int *arr, int n, int k)
{
    // we need kadanes sum, BestSuffixSum, BestPreffixSum and totalSum;
    ll kadane_sum = kadane(arr, n);
    if (k == 1) // this means we have only one array ie A no B array is there
        return kadane_sum;

    // max sum from start
    ll curr_prefix_sum = 0;
    ll best_prefix_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        curr_prefix_sum += arr[i];
        // update the best prefixSum
        best_prefix_sum = max(best_prefix_sum, curr_prefix_sum);
    }
    // by this time current prefix sum will be holding total sum of the arr so..
    ll total_sum = curr_prefix_sum;

    // max sum from end
    ll curr_suffix_sum = 0;
    ll best_suffix_sum = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        curr_suffix_sum += arr[i];
        best_suffix_sum = max(curr_suffix_sum, best_suffix_sum);
    }

    // Main Logic
    ll ans;
    if (total_sum < 0)
        return ans = max(best_prefix_sum + best_suffix_sum, kadane_sum);
    else
        return ans = max(best_prefix_sum + best_suffix_sum + (total_sum * (k - 2)), kadane_sum);
}

int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        // ask user for n and k
        int n, k;
        cin >> n >> k;
        // create an array of size n
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        // call kCON function
        cout << k_concatenation(arr, n, k) << endl;
        delete[] arr;
    }
    return 0;
}