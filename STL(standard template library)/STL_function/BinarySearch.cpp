#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {1, 3, 2, 5, 7, 6};
    sort(arr, arr + 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // return a bool
    cout << binary_search(arr, arr + 6, 3) << endl;
    cout << binary_search(arr, arr + 6, 9) << endl;

    // if We want the location of ocurrence ?? last argument is the value we're searching
    cout << "Address : " << lower_bound(arr, arr + 6, 3) << endl; // this willl return the location of 3 in the arr
    // so to get index
    cout << "Index : " << lower_bound(arr, arr + 6, 3) - arr << endl; // this will give the index ?? if this arr is vector than we can also write arr.begin()
    
    /*IMPORTANT*/
    /*
    - In case element is not present than lower_bound return address of next larger element
    */
}