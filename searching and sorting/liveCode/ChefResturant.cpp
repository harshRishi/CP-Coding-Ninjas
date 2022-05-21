#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> slots; // vector for intervals
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;
            slots.push_back(make_pair(l, r));
        }
        // sort the interval
        sort(slots.begin(), slots.end() /*, comparator*/); // if comparator isn't passed than it will sort according to first int

        while (m--)
        {
            int curr_time;
            cin >> curr_time;
            /*Very Important Concept - lower_bound on pair class object*/
            int index = lower_bound(slots.begin(), slots.end(), make_pair(curr_time, 0)) - slots.begin(); // index of curr_time in the slots' vector

            // Conditions
            if (index == 0) // incase current time found before 0th index in the slots vector
            {
                int ans = slots[index].first - curr_time;
                cout << ans << endl;
            }
            else
            {
                int ans = -1;
                if (slots[index - 1].second > curr_time) // incase LowerBound didn't found the curr-time in slots[index].first
                    ans = 0;
                else if (index < slots.size()) // incase we curr-time lies in bw slots
                    ans = slots[index].first - curr_time;
                cout << ans << endl; // incase ans remained -1 that means positions lies out of bound
            }
        }
    }
    return 0;
}
