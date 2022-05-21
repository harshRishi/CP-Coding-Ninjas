#include <iostream>
using namespace std;

// dynamic programming
int kadane(int *arr, int n)
{
    int bestSum = 0;
    int currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        // if current sum is greater than best sum upadate best sum
        if (currentSum > bestSum)
            bestSum = currentSum;
        // if after adding ith digit our current Sum is -ve than reset currSum to 0 and don't carry this further
        if (currentSum < 0)
            currentSum = 0;
    }
    return bestSum;
}

int main()
{
    int n;
    cin >> n;

    // create an array of size n
    int *arr = new int[n];

    // take array input
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }

    // call kadane's function
    cout << kadane(arr, n) << endl;
// delete dynamically created array
    delete[] arr;
}