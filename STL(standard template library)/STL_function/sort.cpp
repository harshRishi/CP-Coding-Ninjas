#include <iostream>
#include <algorithm>
using namespace std;

struct Interval
{
    int st;
    int et;
};

// our compare function for sorting
bool compare(Interval a, Interval b)
{
    return a.st < b.st; // for increasing order
    // return (a.st > b.st) // for decreasing order
}

int main()
{
    int arr[] = {1, 2, 38, 64, 23, 1, 4, 5};
    // sort increasing
    sort(arr, arr + 8);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    // sort in decreasing
    sort(arr, arr + 8, greater<int>());
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // sort according to us
    Interval array[] = {{6, 4}, {3, 4}, {4, 6}, {8, 13}};
    sort(array, array + 4, compare); // custom Sorting
    for (int i = 0; i < 4; i++)
    {
        cout << array[i].st << " : " << array[i].et << endl;
    }

    return 0;
}