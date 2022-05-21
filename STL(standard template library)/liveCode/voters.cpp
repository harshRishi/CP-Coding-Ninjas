#include <bits/stdc++.h>
using namespace std;

vector<int> getVoters(int arr[], int n)
{
    // sort this voter list
    sort(arr, arr + n);
    vector<int> ans;

    // count frequence of each voters
    for (int i = 0; i < n;)
    {
        int count = 0;
        int j = i; // this will iterate from i till elements are same
        // run this while till element mis_matches
        while (j < n && (arr[j] == arr[i]))
        {
            count++; // counting frequence of the number
            j++;
        }
        // check the count
        if (count >= 2)
            ans.push_back(arr[i]);

        // as j has already counted same element till jth index so now i should become i
        i = j;
    }
    // return the final voters' list
    return ans;
}

int main()
{
    // ask user for different voter lists
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    // created a list of voters
    int size = n1 + n2 + n3;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    vector<int> voters = getVoters(arr, size);

    cout << voters.size() << endl;
    for (int i = 0; i < voters.size(); i++)
    {
        cout << voters[i] << endl; // printing the final voters
    }
    return 0;
}