/*
Merge Sort Code
Send Feedback
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
First line of input will contain T number of test cases
First line of every input will contain a single integer N size of the input array.
second line of each input will contain N space-separated integers.
Output format :
For every test case print, array elements in increasing order (separated by space) in a separate line.
Constraints :
1 <= T <= 10
1 <= n <= 10^5
Sample Input 1 :
1
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
1
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/

#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int si, int ei){
    if(si < ei){
        int mid = (ei+si)/2;
        merge(arr, si, mid);
        merge(arr, mid+1, ei);

        int s=ei-si+1;
        int *mergeArr=new int[s];

        int i=si, j=mid+1, fillerIndex=0;
        for(;i<=mid && j<=ei;)
            (arr[i]>arr[j]) ? mergeArr[fillerIndex++]=arr[j++] : mergeArr[fillerIndex++]=arr[i++];

        while(i<=mid)
            mergeArr[fillerIndex++]=arr[i++];
        while(j<=ei)
            mergeArr[fillerIndex++]=arr[j++];

        int k=si;
        for(int p=0;p<s;p++)
            arr[k++]=mergeArr[p];

        delete[] mergeArr;
    }
}

void mergeSort(int *arr, int n)
{
    if(n <= 0) 
        return;
    merge(arr, 0, n-1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        mergeSort(arr, n);
        
        int i=0;
        while(n--){
            cout<<arr[i++]<<" ";
        }
        cout << "\n";
    }
    // write your code here
    return 0;
}
