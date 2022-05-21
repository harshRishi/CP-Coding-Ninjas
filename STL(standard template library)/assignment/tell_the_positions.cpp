#include <bits/stdc++.h>
using namespace std;

// get<_> return the value of that perticular data member in tuple

bool comparator(tuple<int, string, int> x, tuple<int, string, int> y)
{
    if (get<2>(x) == get<2>(y)) // in case both have same marks
    {
        return get<0>(x) < get<0>(y); // compare there roll numbers
    }
    return get<2>(x) > get<2>(y); // else comare scores
}

int main()
{
    int n;
    cin >> n;
    vector<tuple<int, string, int>> m; // vector to store the student list
    int m1, m2, m3;                    // scores of student s
    string s;                          // student name
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        cin >> m1 >> m2 >> m3;
        m.push_back(make_tuple(i, s, m1 + m2 + m3)); // push this student in the list of student
    }
    sort(m.begin(), m.end(), comparator); // sort this array from start to end with our comparator
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " " << get<1>(m[i]); // print roll number and name
        cout << endl;
    }
}