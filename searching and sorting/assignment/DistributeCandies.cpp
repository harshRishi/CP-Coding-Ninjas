#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll *arr, int n, ll k, ll num_candies)
{
    ll i = 0;
    while (n-- && k > 0)
    {
        ll pNum = arr[i++] / num_candies;

        if (pNum >= 1)
            k = k - pNum;
    }
    if (k > 0)
        return false;
    else
        return true;
}

ll ans = 0;
void distributeCandies(ll *arr, int n, ll k, ll minCandies, ll maxCandies)
{
    ll num_candies = ((maxCandies + minCandies) / 2);
    if (check(arr, n, k, num_candies))
    {
        ans = num_candies;
        if (minCandies < maxCandies)
            distributeCandies(arr, n, k, num_candies + 1, maxCandies);
    }
    else
    {
        if (minCandies < maxCandies)
            distributeCandies(arr, n, k, minCandies, num_candies - 1);
    }
}

int main()
{
    // write your code
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        ans = 0;
        ll *arr = new ll[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        ll maxCandies = *max_element(arr, arr + n);

        distributeCandies(arr, n, k, 1, maxCandies);
        cout << ans << endl;
        delete[] arr;
    }
    return 0;
}