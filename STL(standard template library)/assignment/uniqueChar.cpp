#include <bits/stdc++.h>
string uniqueChar(string str)
{
    // Write your code here
    unordered_map<char, bool> freq;

    for (int i = 0; i < str.length(); i++)
    {
        freq[str[i]] = true;
    }

    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (freq[str[i]])
        {
            ans += str[i];
            freq[str[i]] = false;
        }
    }
    return ans;
}