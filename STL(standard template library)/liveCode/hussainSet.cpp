#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    // ask user for multiset size and than number of querries
    int n, m;
    cin >> n >> m;

    // create a array of size n
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // sort this arr
    sort(arr, arr + n);

    // create queue to store the querries
    queue<ll> q;

    int count_m = 0;
    int endPointer = n - 1; // Index to maintain the max number of the array after pick_up

    while (m--)
    {
        // question ask by hussain to hasan
        int curr_m;
        cin >> curr_m;

        // variable to store the maxNumber
        ll ans;
        for (; count_m < curr_m; count_m++) // this loop will find all possible ans till 5 and than print only the 5th ans
        {
            // very important endPointer if less than 0 that means array is exausted and now take elements from the queue
            if (endPointer >= 0 && (q.empty() || arr[endPointer] >= q.front())) // is array's last element is greater than q's front element
            {
                ans = arr[endPointer];
                endPointer--;
            }
            else // if q's element is greater
            {
                ans = q.front();
                q.pop();
            }
            // now if ans / 2 != 0 than insert the ans / 2 in the queue
            if (ans / 2 != 0)
                q.push(ans / 2);
        }
        cout << ans << endl; // print the ans to corresponding q
    }
    return 0;
}