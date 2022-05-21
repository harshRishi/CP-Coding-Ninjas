#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        // create a left product arrary(ie if ith element is concidered than product of ith+1 will be calc and placed)
        vector<int> productArray(n, 0);

        int lp = 1;
        for (int i = 0; i < n; i++)
        {
            productArray[i] = lp;
            lp *= nums[i];
        }
        // by this time our product arry will have left_product data so now we're going to over_write wit with right product data
        int rp = 1;
        for (int i = n - 1; i >= 0; i++)
        {
            productArray[i] *= rp;
            rp *= nums[i];
        }
        return productArray;
    }
};

/*
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = nums[0]; // left sum of first number
        for (int i = 1; i < n; i++)
        {
            left[i] = nums[i] * left[i - 1];
        }
        right[n - 1] = nums[n - 1]; // right sum of the last number
        for (int j = n - 2; j >= 0; j--)
        {
            right[j] = nums[j] * right[j + 1];
        }
        vector<int> r(n, 0);
        if (n > 1)
        {
            r[0] = right[1];
            r[n - 1] = left[n - 2];
        }
        for (int i = 1; i < n - 1; i++)
        {
            // it equals to the left multiplies the right.
            r[i] = left[i - 1] * right[i + 1];
        }
        return r;
    }
};
* /