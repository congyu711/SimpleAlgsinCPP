#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int ans=0,n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int res=0,i=0;
        for(i=n-1;i>=0;i--)
        {
            res+=satisfaction[i];
            if(res<=0)  break;
        }
        for(int j=i+1;j<n;j++)
        {
            ans+=satisfaction[j]*(j-i);
            //cout<<ans<<endl;
        }
        return ans;
    }
};
int main()
{
    vector<int> arr={-1,-8,0,5,-9};
    Solution a;
    cout<<a.maxSatisfaction(arr)<<endl;
}