#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int x, int y){
    ll m = pow(10, 9)+7;
    ll ans = 1;
    for(int i=0;i<y;i++){
        ans = (ans * (ll)x)%m;
    }
    return (int)ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin>>x>>y;
        cout<<solve(x, y)<<"\n";
    }
    // write your code here
    return 0;
}
