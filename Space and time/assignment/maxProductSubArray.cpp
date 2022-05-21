#include <bits/stdc++.h>
using namespace std;

/*
int maxProduct(vector<int> &nums)
{
    int max_ending_here = 1; // this will store the maximum possible positive number
    int min_ending_here = 1; // this will store the minimum possble -ve number if there is no -ve number in the array than this will be 1;

    int max_so_far = 0; // this is our ans which store the maximum product of subArray

    for (int i = 0; i < nums.size(); i++)
    {
        // In case nums[i] is +ve
        if (nums[i] > 0)
        {
            max_ending_here = max_ending_here * nums[i];
            min_ending_here = min(1, min_ending_here * nums[i]); // basically if min_ending is -ve so after multiplicatin with a +ve number gives us the greater -ve value
        }
        else if (nums[i] < 0) // nums of i is -ve
        {
            // to store the un-updated max_ending_here
            int temp = max_ending_here;
            max_ending_here = max(1, min_ending_here * nums[i]); // in this case also min_ending is -ve and as we know nums is also -ve it can give us max number
            min_ending_here = temp * nums[i];                    // this is obvio to get min number we need to multiple the max with some -ve number
        }
        else // In Case nums[i] is 0
        {
            // reset the max_ending and min_ending as here subArray brokes
            min_ending_here = 0; // as we've reached 0 that means now min product is 0
            max_ending_here = 1;
        }
        // update max_so_far if possible
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}
*/
// TIME COMPLEXITY:- O(N)
// SPACE COMPLEXIY:- O(1)
int maxProduct(vector<int> &nums)
{
    int ans = nums[0], max_prod = nums[0], min_prod = nums[0]; // initialize max product,min product and answer
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < 0) // if number is negative, we will swap max prod and min prod
            swap(max_prod, min_prod);
        max_prod = max(nums[i], max_prod * nums[i]); // find current max prod each time
        min_prod = min(nums[i], min_prod * nums[i]); // find current min prod each time
        ans = max(ans, max_prod);                    // store the maximum product each time
    }
    return ans;
}

int main()
{
}
