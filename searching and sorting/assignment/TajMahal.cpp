#include <bits/stdc++.h>
using namespace std;
#define long long int

signed main()
{
    // write your code here
    int n;
    cin >> n;
    int window[n];
    for (int i = 0; i < n; i++)
        cin >> window[i];

    
    // formula : if (window[i] - (i+(cycle*n)) <= 0) that mean at reaching to that ith index window is having no line
    // we can also write cycle = (window[i] - i)/ n;

    int time[n]; // O(n) // this will arr will going to store the cycles required for ith window to get ticket
    for (int i = 0; i < n; i++)
    {
        if (window[i] - i <= 0) // this means i iself is greater than window[i]
            time[i] = (window[i] - i) / n;
        else if ((window[i] - i) % n != 0) //here we're checking window[i] - i % n as maybe after diving by n it might result into some fractional value which can be redued to integer so if it is reduce we add 1 to the value of (window[i]-i / n) + 1
            time[i] = ((window[i] - i) / n) + 1;
        else
            time[i] = (window[i] - i) / n;

        // cout << time[i] << " ";
    }
    int ans = *min_element(time, time + n);
    for (int i = 0; i < n; i++)
    {
        if (time[i] == ans)
        {
            cout << i + 1 << '\n';
            break;
        }
    }
    /*
    int cycle = 0;
    for (int i = 0; i < n; i++)
    {
        if (window[i] <= (i + (cycle * n)))
        {
            cout << i + 1 << '\n';
            return 0;
        }
        if (i == n - 1)
        {
            cycle++;
            i = 0;
        }
    }
    */
    return 0;
}