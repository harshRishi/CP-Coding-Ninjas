#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n)
{
    int i = 0, j = 1;
    while (i < n && j < n)
    {
        if (arr[i] == arr[j] + 1)
        {
            swap(arr[i], arr[j]);
            while (i > 0 && arr[i] == arr[i - 1] - 1)
            {
                swap(arr[i], arr[i - 1]);
                i--;
            }
            i = j;
            j = i + 1;
        }
        else
        {
            i++;
            j++;
        }
    }
    for (int k = 1; k < n; k++)
    {
        if (arr[k - 1] > arr[k])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        if (isPossible(arr, n))
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
    // write your code here
    return 0;
}