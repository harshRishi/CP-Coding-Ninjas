#include <bits/stdc++.h>
using namespace std;

int solve(int h)
{
    if (h <= 1)
        return 1;
    int m = pow(10, 9) + 7;
    int h1 = solve(h - 1);
    int h2 = solve(h - 2);

    long x = (long)h1 * h1; // typecast
    long y = (long)2 * h1 * h2;

    return ((int)(x % m) + (int)(y % m)) % m; // first property of mudulo is used ie [(a+b)%m == (a%m + b%m)%m]
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h;
        cin >> h;
        cout << solve(h);
        cout << '\n';
    }
    // write your code here
    return 0;
}
