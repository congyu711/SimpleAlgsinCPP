#include <bits/stdc++.h>
using namespace std;
//actually find the Kth number in two sorted arrays.
class Solution
{
public:
    double bs(vector<int> &nums1, int s1, int e1, vector<int> &nums2, int s2, int e2, int k)
    {
        int len1=e1-s1+1,len2=e2-s2+1;
        if(len1==0) return nums2[s2+k-1];
        if(len2==0) return nums1[s1+k-1];
        if(k==1)    return min(nums2[s2],nums1[s1]);
        int a=s1+min(k/2,len1)-1,b=s2+min(,len2,k/2)-1;
        if(nums1[a]>nums2[b])   return 
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        int lm = (n + m + 1) / 2;
        int rm = (n + m + 2) / 2;
        return (bs(nums1, 0, n1 - 1, nums2, 0, n2 - 1, lm) + bs(nums1, 0, n1 - 1, nums2, 0, n2 - 1, rm)) / 2;
    }
};
int main()
{
}