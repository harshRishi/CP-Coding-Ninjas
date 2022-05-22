#include <bits/stdc++.h>
using namespace std;

// STL cannot be passed directly they need to be passed by refrence or as a pointer 
// in case of arr we dont need to pass refrence as they send their address

void replaceCharacter(string &s, char c1, char c2, int i) // recursive
{
    if (s.length() == i)
        return;

    if (s[i] == c1)
        s[i] = c2;

    replaceCharacter(s, c1, c2, i + 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        char a, x;
        cin >> a >> x;
        replaceCharacter(s, a, x, 0);
        cout << s << '\n';
    }

    /* iterative
    while(t--){
        string s;

        cin>>s;
        char a, x;
        cin>>a>>x;

        for(int i=0;i<s.length();i++){
            if(s[i]==a){
                s[i]=x;
            }
        }
        for(int i=0;i<s.length();i++)
            cout<<s[i]<<'\n';
    }
    */
    // write your code here
    return 0;
}