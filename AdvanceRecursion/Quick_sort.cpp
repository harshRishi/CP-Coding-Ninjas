#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int input[], int start, int end)
{
    int pivot = input[end];
    int pi = start;

    for (int i = start; i < end; i++)
    {
        if (input[i] < pivot)
        {
            swap(&input[i], &input[pi]);
            pi++;
            // int temp = input[i];
            // input[i] = input[pi];
            // input[pi++] = temp;
        }
    }
    swap(&input[pi], &input[end]);
    // int temp = input[pi];
    // input[pi] = input[end];
    // input[end] = temp;

    return pi;
}

void sorting(int input[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pi = partition(input, start, end);
    sorting(input, start, pi - 1);
    sorting(input, pi + 1, end);
}

void quickSort(int input[], int size)
{
    sorting(input, 0, size - 1);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;

        int *input = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }

        quickSort(input, n);
        for (int i = 0; i < n; i++)
        {
            cout << input[i] << " ";
        }
        cout<<'\n';
        delete[] input;
    }
    return 0;
}
