#include <iostream>
#include <string>
using namespace std;

int main()
{
    // created string
    string s = "Harsh";
    cout << s << endl;
    // copied  the stirng s to s1 from 2 to 2+4
    string s1(s, 2, 4);
    cout << s1 << endl;

    // compare two strings
    if ((s1.compare(s)) == 0)
        cout << s1 << " is equal to " << s << endl;
    else
        cout << s1 >> " is not equal to " << s << endl;

    // Compares 5 characters from index number 3 of s2 with s1
    if ((s1.compare(3, 5, s2)) == 0)
        cout << "Here, " << s1 << " are " << s;

    else
        cout << "Strings didn't match ";

    // Compares 5 characters from index number 0 of s1 with
    // 4 characters from index 3 of s2
    if ((s.compare(0, 5, s1, 3, 4)) == 0)
        cout << "Welcome to " << s1 << s << " World";

    else
        cout << "Strings didn't match ";
}