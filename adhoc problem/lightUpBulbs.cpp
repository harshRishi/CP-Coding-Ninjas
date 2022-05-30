#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
// #define int long long
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(ll i=a; i<b; i++)

int main()
{
    ll n, x, y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    ll grp0 = 0;
    if(s[0] == '0') {
        grp0=1;
    }
    rep(i,1,n){
		if((s[i-1]=='1') && (s[i]=='0'))
		{
			grp0 += 1;
		}
    }
    if(grp0==0)
        cout << 0;
    else {
        cout << ((grp0-1) * min(x, y)) + y;
    }
    return 0;
}