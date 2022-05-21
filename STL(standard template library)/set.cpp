#include <iostream>
#include <set>
using namespace std;

/* Set uses Balanced binary search Tree */ // BST so O(logN)
int main()
{
    // creted a set
    set<int> s;

    int arr[] = {1, 2, 3, 4, 5, 6, 5};
    for (int i = 0; i < 7; i++)
        s.insert(arr[i]); // inserting a value in the set

    // set also have an iterator
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
        cout << *it << endl;

    // search something in set
    if (s.find(6) != s.end()) // this find function returns iterator
        cout << "Found the element " << 6 << endl;
    else
        cout << "element " << 6 << " is not present" << endl;
}