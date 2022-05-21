#include <iostream>
#include <utility> // utility is also included in iostream and namespace so not that important to write
using namespace std;

int main()
{
    int x = 10;
    int y = 12;
    swap(x, y);
    cout << x << endl;
    cout << y << endl;
}
