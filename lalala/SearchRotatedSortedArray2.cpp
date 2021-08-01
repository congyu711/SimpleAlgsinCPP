#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //utf-8
    //nums里有重复元素,为保证仍能通过比较mid和l/r确定哪一个半是有序的,直接去掉头尾相同的元素
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1, mid;
        if (nums[l] == target)
            return true;
        if (nums[r] == target)
            return true;

        while (l <= r)
        {
            while (l < r && nums[l] == nums[0])
                l++;
            while (l < r && nums[r] == nums[n - 1])
                r--;
            int mid = (l + r) >> 1;
            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[mid] < nums[r]) //youbian youxu
            {
                if (nums[mid] < target && target <= nums[r])
                {
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            else //zuobian youxu
            {
                if (target >= nums[l] && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
        }
        return false;
    }
};
int main()
{
}