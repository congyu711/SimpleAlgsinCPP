#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //maxl is the maxium of the third number(should be lower than the second num and the first num), 
    //the Monotonic Stack makes sure the it is lower than the second num, and if we can find a num which has smaller index and lower than maxl, then the search is done.
    bool find132pattern(vector<int> &nums)
    {
        stack<int> st;
        int n = nums.size();
        int maxl = -1e9-2;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < maxl)
                return true;
            while (!st.empty() && st.top() < nums[i])
            {
                maxl = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
int main()
{
    vector<int> arr = {1, 1, 1, 1, 1, 1};
    vector<int> arr2 = {1, 3, 2, 2, 2};
    cout << ((Solution *)NULL)->find132pattern(arr) << endl;
    cout << ((Solution *)NULL)->find132pattern(arr2) << endl;
}