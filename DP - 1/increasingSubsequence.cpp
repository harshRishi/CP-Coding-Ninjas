#include <bits/stdc++.h>
using namespace std;

void solve() // O(n^2)
{
    int n;
    cin >> n;
    int *arr = new int[n]();
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int *dp = new int[n](); // () after [n] will initailize the whole arr with zero
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        int temp = i;
        while (temp--)
        {
            if (arr[i] > arr[temp] && dp[i] <= dp[temp])
                dp[i] = dp[temp] + 1; // increase the subsequence
        }
    }

    int ans = *max_element(dp, dp + n);
    cout << ans;
    delete[] dp;
    delete[] arr;
    return;
}

signed main()
{
    // Take input faster
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}

/*
2
7
1 5 7 2 9 4 8
7
4 3 9 7 6 8 20
*/