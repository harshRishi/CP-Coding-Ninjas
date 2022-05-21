#include <bits/stdc++.h>
using namespace std;

// find char corresponding to i
char getChar(int i)
{
    // typeCast int to char
    return (char)(i + 97);
}

void printPalindromicString(string s)
{
    int n = s.length();
    // create a map to store key and value ie. char and positions of char respectivly
    map<char, vector<int>> indexMap;
    for (int i = 0; i < n; i++)
    {
        indexMap[s[i]].push_back(i); // as our index in quetion is from 0 to n-1
    }

    // now iterate this map can look if there are more than one odd vector size
    int odd_counter = 0;
    for (int i = 0; i < 26; i++) // as there;re only 26 char possible
    {
        if (indexMap[getChar(i)].size() % 2 != 0) // check if size is odd if yes than increase the counter
            odd_counter++;
    }
    // if odd_counter if more than one return -1 as palindrom is not possible
    if (odd_counter > 1)
    {
        cout << "-1";
        return;
    }

    int ans[n];
    int start = 0, end = n - 1;
    for (int i = 0; i < 26; i++)
    {
        int currChar = getChar(i);
        for (int j = 0; j < indexMap[currChar].size(); j += 2) // j+2 as we are putting pair at a time at start and at the end
        {
            // incase vector size is odd
            if ((indexMap[currChar].size() - j) == 1) // this mean : as j is increased by 2 there if a single char is left that means that char is odd
            {
                ans[n / 2] = indexMap[currChar][j]; // odd one will alaways occupy the centre
                continue;
            }

            ans[start++] = indexMap[currChar][j];   // indexMap[currChar] is a vector and we're looking at jth char
            ans[end--] = indexMap[currChar][j + 1]; // pointing to next int in vector.at(currChar)
        }
    }
    // print the permuted palindromic arry Indices
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] + 1 << " "; // +1 as we're taking index from 1 to n
    }
    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        // call our palindromic function
        printPalindromicString(s);
        cout << endl;
    }

    return 0;
}