#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (nums[mid] < nums[r])
                r = mid-1;
            else if (nums[mid] > nums[r])
                l = mid + 1;
            else    r--;
        }
        return nums[l];
    }
};
int main()
{
}