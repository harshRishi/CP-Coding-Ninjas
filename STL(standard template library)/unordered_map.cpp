#include <iostream>
#include <unordered_map>
using namespace std;

/* unordered_map uses hashTable */ // O(1) in avg case but in worst O(n) which is rear
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 5};

    // created a map with key and value as integers
    unordered_map<int, int> m;
    for (int i = 0; i < 7; i++)
    {
        m[arr[i]]++; // OR m[arr[i]] = m[arr[i]] + 1;
    }

    // unordered_map has an iterator
    unordered_map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        // as it is pointer and it is pointing a pair so that pair will have first as key and second as value
        cout << it->first << " : " << it->second << endl;
    }

    // search operations
    if (m.find(5) != m.end()) // find function also return an iterator
        cout << "Found!";
    else
        cout << "Not Found!";

    // delete operations
    m.erase(1); // this will remove key 1 with it's value
}