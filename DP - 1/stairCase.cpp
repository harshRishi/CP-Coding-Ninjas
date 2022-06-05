#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define MOD 1000000007
#define int long long

int dynamic(int n){
    int *dp=new int[n+1]();
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i=3;i<=n;i++){
        dp[i] = ((dp[i-1]%MOD) + (dp[i-2]%MOD) + (dp[i-3]%MOD))%MOD;
    }
    return dp[n];
}

/*
int memoization(int n, int *memo){
    if(n==0 || n==1){
        return 1;
    } 
    if(n==2){
        return 2;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    int ans = (memoization(n-1, memo)%MOD) + (memoization(n-2, memo)%MOD) + (memoization(n-3, memo)%MOD);
    memo[n] = ans%MOD;
    return memo[n];
}
*/
void solve(){
    int n;
    cin >> n;
    int *memo = new int[n+1];
    for(int i=0;i<=n;i++){
        memo[i] = -1;
    }
    cout << dynamic(n/*, memo*/);
}

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        solve();
        cout << '\n';
    }
    // write your code here
    return 0;
}