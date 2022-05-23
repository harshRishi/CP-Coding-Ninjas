#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n){
    ll prod = 1;
    ll m = pow(10, 9)+7;
    for(int i=2;i<=n;i++){
        prod = (prod*i)%m; 
    }
    return (int)prod;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solve(n);
        cout<<'\n';
    }
    // write your code here
    return 0;
}
