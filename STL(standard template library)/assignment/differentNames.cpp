#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Write your code here
    string str;
    getline(cin, str);

    unordered_map<string, int> nameFreq;
    string name = ""; // intializing the empty string
    for (int i = 0; i <= str.length(); i++)
    {
        if (str[i] == '\0') // here we've include this nuLL so that we can update the last name as well before getting out this loop  and therefore we've included '\0' char as well
        {
            nameFreq[name]++;
            break;
        }
        if (str[i] != ' ') // if we encounter space in our stream
        {
            name += str[i]; // keep adding char to form names
            continue;
        }
        nameFreq[name]++;
        name = ""; // reset the string for further char and names

        /*int j = i;
         while(str[j] != ' ' && str[j] != '\0'){
           //  s.push_back(str[j]);
             j++;
         }
         string s = str.substr(i, j-i);
         i = j;
         nameFreq[s] = nameFreq[s]+1;
         */
    }

    // by this time our map should contain all freq corresponding to their respective names
    unordered_map<string, int>::iterator it;
    bool check = false;
    for (it = nameFreq.begin(); it != nameFreq.end(); it++)
    {
        if (it->second > 1) // in Case freq of any name is greater than 1 {it->second is value}
        {
            cout << it->first << " " << it->second << endl;
            check = true;
        }
    }
    if (!check) // this means we never encountered any name with freq greater than 1
    {
        cout << -1 << endl;
    }
}

// Abhishek harshit Ayush harshit Ayush Iti Deepak Ayush Iti