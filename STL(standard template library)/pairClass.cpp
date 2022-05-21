#include <iostream>
#include <utility> // to use pair class
using namespace std;

int main()
{
    // first is int and char is second
    pair<int, char> p;
    p = make_pair(2, 'b'); // this is also as way to make pair

    pair<int, char> p2(1, 'a');
    cout << p2.first << " " << p2.second << endl;
}