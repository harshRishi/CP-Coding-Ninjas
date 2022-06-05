#include<iostream>
#include<algorithm>
using namespace std;

int* lis(int* input, int n)
{
	int* output = new int[n];
	output[0] = 1;
	for (int i = 1; i < n; i++)
	{
		int current_maximum = 0;
		for (int j = 0; j < i; j++)
		{
			if (input[i] > input[j])
			{
				current_maximum = max(current_maximum, output[j]);
			}
		}
		output[i] = current_maximum + 1;
	}
	return output;
}
int* lis_back(int* input, int n)
{
	int* output = new int[n];
	output[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--)
	{
		int current_maximum = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (input[i] > input[j])
			{
				current_maximum = max(current_maximum, output[j]);
			}
		}
		output[i] = current_maximum + 1;
	}
	return output;
}
int longestBitonicSubarray(int* input, int n)
{
	int* longest_increasing_subsequence = lis(input, n);
	int* longest_increasing_subsequence_from_back = lis_back(input, n);
	int maximum = 2; // == 2 ??
	for (int i = 0; i < n; i++)
	{
		maximum = max(maximum, longest_increasing_subsequence_from_back[i] + longest_increasing_subsequence[i] - 1); //-1??
	}
	delete[] longest_increasing_subsequence;
	delete[] longest_increasing_subsequence_from_back;
	return maximum;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *input = new int[n];
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            input[i] = a;
        }
        cout << longestBitonicSubarray(input, n);
        cout<<'\n';
    }
    // write your code here
    return 0;
}