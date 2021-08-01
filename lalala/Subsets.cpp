#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        // auto it=unique(nums.begin(),nums.end());
        // nums.erase(it,nums.end());
        int n = nums.size();
        int t = (1 << n);
        vector<vector<int>> ans;
        while (t--)
        {
            int c = t;
            vector<int> tmp;
            for (int i = 0; i < n; i++)
            {
                if (c & 1)
                    tmp.push_back(nums[i]);
                c >>= 1;
            }
            ans.push_back(tmp);
        }
        return ans;
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        ans.push_back(v);
        int right = 1, left = 0, len = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0 && (nums[i] == nums[i - 1]))
                left = ans.size() - len;
            else
                left = 0;
            right = ans.size();
            len = right - left;
            for (int j = left; j < right; ++j)
            {
                v = ans[j];
                v.push_back(nums[i]);
                ans.push_back(v);
            }
        }
        return ans;
    }
};
int main()
{
    Solution a;
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> ans = a.subsetsWithDup(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}