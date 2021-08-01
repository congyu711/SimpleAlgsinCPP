#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto lamb=[](const int &a,const int &b)
        {
            int sa=10,sb=10;
            while(sa<=a)    sa*=10;
            while(sb<=b)    sb*=10;
            return sb*a+b > sa*b+a;
        };
        sort(nums.begin(),nums.end(),lamb);
        string a;
        for(int i=0;i<nums.size();i++)
        {
            a+=to_string(nums[i]);
        }
        return a;
    }
};
int main()
{
    vector<int> arr={1,444,442};
    Solution a;
    cout<<a.largestNumber(arr)<<endl;
}