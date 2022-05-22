/*Remove Duplicates Recursively
Send Feedback
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
First line of input will contain T number of test cases
Next T line will contain the string S
Output Format :
For every test case print the answer in a separate line
Constraints :
1 <= T <= 10
1 <= |S| <= 10^4
where |S| represents the length of string
Sample Input 1 :
1
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
1
xxxyyyzwwzzz
Sample Output 2 :
xyzwz*/

#include<bits/stdc++.h>
using namespace std;

void removeConsecutiveDuplicates(char s[]){
    if(s[0] != '\0'){
        if(s[0]==s[1]){
            int i=0;
            while(s[i]!='\0'){
                s[i]=s[i+1];
                i++;
            }
            removeConsecutiveDuplicates(s);
        }
        removeConsecutiveDuplicates(s+1);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        char s[10000];
        cin>>s;
        removeConsecutiveDuplicates(s);
        cout<<s<<'\n';
    }
    // write your code here
    return 0;
}
