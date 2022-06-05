#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (abs(i + 1 - a[i]) > 2)
                flag = false;
        }
        int count = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] != i + 1)
            {
                if (((i - 1) >= 0 && a[i - 1] == i + 1))
                {
                    count++;
                    swap(a[i], a[i - 1]);
                }
                else if (((i - 2) >= 0 && a[i - 2] == i + 1))
                {
                    count = count + 2;
                    a[i - 2] = a[i - 1];
                    a[i - 1] = a[i];
                    a[i] = i + 1;
                }
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
            cout << count << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}