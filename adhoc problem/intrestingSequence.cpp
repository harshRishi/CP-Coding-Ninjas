#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int n, l, k;
	cin >> n >> l >> k;
	int arr[n];
	int min1 = INT_MAX, max1 = INT_MIN;
	int ans = 1e15;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		min1 = min(min1, arr[i]);
		max1 = max(max1, arr[i]);
	}
	for (int j = min1; j <= max1; j++)
	{
		int inc = 0, dec = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] < j)
				inc += j - arr[i];
			else
				dec += arr[i] - j;
		}

		if (dec > inc)
			continue;

		// ans = min(ans, dec * l + (inc - dec) * k);
        ans = min(ans , 1ll * dec * l + (inc - dec) * 1ll * k); // here we've type casted the k and l to 64 bit by notation of 1ll - ie 1 of 64 bit
	}
	cout << ans << endl;
	return 0;
}