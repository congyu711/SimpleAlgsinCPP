#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1,mid;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<nums[r])  //youbian youxu
            {
                if(nums[mid]<target&&target<=nums[r])
                {
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
            else                        //zuobian youxu
            {
                if(target>=nums[l]&&target<nums[mid])
                {
                    r=mid-1;
                }
                else    l=mid+1;
            }
        }
        return -1;
    }
};
int main()
{
    
}