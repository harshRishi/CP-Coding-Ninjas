#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define MOD 1000000007
#define int long long
/*
int minCost(int **input, int si, int sj, int ei, int ej, int **output){
    if(si == ei && sj == ej){
        return input[ei][ej];
    }
    if(si > ei || sj > ej){
        return INT_MAX;
    }
    if(output[si][sj] != -1){
        return output[si][sj];
    }
    int down = minCost(input, si+1, sj, ei, ej);
    int diagonal = minCost(input, si+1, sj+1, ei, ej);
    int right = minCost(input, si, sj+1, ei, ej);

    output[si][sj] = input[si][sj] + min({down, diagonal, right});
    return output[si][sj];
}
*/
// Dynamic solution
int minCost(int** input, int m, int n) {
	int ** dp = new int*[m];
	for (int i = 0; i < m; i++) {
		dp[i] = new int[n];
	}
	dp[m - 1][n-1] = input[m-1][n-1];
	for (int i = m - 2; i >= 0; i--) {
		dp[i][n -1] = dp[i + 1][n-1] + input[i][n-1];
	}

	for (int j = n - 2; j >=0; j--) {
		dp[m -1][j] = dp[m - 1][j + 1] + input[m-1][j];
	}

	for (int i = m - 2; i >=0; i--) {
		for (int j = n - 2; j >=0 ; j--) {
			dp[i][j] = input[i][j] + min({dp[i+1][j], dp[i+1][j+1], dp[i][j + 1]});
		}
	}
	int ans = dp[0][0];
    for(int i=0;i<m;i++){
        delete[] arr[i];
    }
    delete[] arr;
    return ans;
}

void solve(){
    int n, m;
    cin>>m>>n;
    int **arr = new int*[m];
    for(int i =0;i<m;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;i++){
            int a = 0;
            cin >> a;
            arr[i][j] = a;
        }
    }
    /*
    int **memo = new int*[m];
    for(int i =0;i<m;i++){
        memo[i]=new int[n];
        for(int j=0;j<n;j++){
            memo[i][j] = -1;
        }
    }*/
    cout<<minCost(arr, m, n/*0 0,m-1,n-1,memo*/);
    return;
}

signed main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
        cout << '\n';
    }
    return 0;
}