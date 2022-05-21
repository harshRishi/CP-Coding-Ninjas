#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(5);         // created an dynamic array of size 5
    vector<int>::iterator it; // created an iterator
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = i + 1; // OR v.push-back(i+1);
        // to get element use - v.at();
    }

    for (it = v.begin(); it != v.end(); it++) // tavelling the vector using iterator
    {

        cout << *it << endl; // this will print the element where it is pointing {de_reference operator} 
    }

    return 0;
}