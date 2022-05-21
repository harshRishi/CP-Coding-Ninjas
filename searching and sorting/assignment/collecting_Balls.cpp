#include <bits/stdc++.h>
using namespace std;

#define int long long

int binary_search(int n, int si, int ei, int ans)
{
    if (si > ei)
        return ans;

    int N = n;
    int mid = (si + ei) / 2;
    int k = mid;
    int sharma = 0, singh = 0;

    while (N >= k && N > 0)
    {
        sharma += k;
        N = N - k;
        singh += (N) / 10;
        N = N - (N) / 10;
    }
    sharma += N;
    if (2 * sharma < n)
    {
        return binary_search(n, mid + 1, ei, ans);
    }
    else
    {
        ans = k;
        return binary_search(n, si, mid - 1, ans);
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k = binary_search(n, 1, n, 0);
        cout << k << '\n';
    }
    // write your code here
    return 0;
}