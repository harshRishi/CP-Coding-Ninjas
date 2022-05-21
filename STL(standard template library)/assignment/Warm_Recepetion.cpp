#include <bits/stdc++.h>
using namespace std;

int main()
{ // arl - arvel time && dep - departure time
    int n;
    cin >> n;
    int arl[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arl[i];
    }

    int dep[n];

    for (int i = 0; i < n; i++)
    {
        cin >> dep[i];
    }

    sort(arl, arl + n); // sort the avl time 
    sort(dep, dep + n); // sort the dep time

    int j = 0, chairs = 0;
    for (int i = 0; i < n; i++)
    {
        if (arl[i] < dep[j]) // if arl time of ith person is less than jth person departure time than for that we need a extra chair 
        {
            chairs++;
            continue; // we conti coz' now check for other person arl time before checking next departure time {ie by incresing value of j}
        }
        j++;
    }

    cout << chairs << '\n';
    return 0;
}