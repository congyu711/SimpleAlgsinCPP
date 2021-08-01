//3_15 beat 100% c++ users!!!
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int i = 0, j = 0;
        int ii[4] = {0, 1, 0, -1};
        int jj[4] = {1, 0, -1, 0};
        int dir = 0;
        int nn=n*n;
        int cnt=1;
        vector<vector<int>> ans(n,vector<int>(n,-1));
        if(n==1)
        {
            ans[0][0]=1;
            return ans;
        }
        while (1)
        {
            //越界
            if (i + ii[dir % 4] >= n || i + ii[dir % 4] < 0 ||
                j + jj[dir % 4] < 0 || j + jj[dir % 4] >= n)
            {
                dir++;
                dir %= 4;
            }
            //已经跑过
            else if (ans[i + ii[dir % 4]][j + jj[dir % 4]] != -1)
            {
                if (ans[i + ii[(dir + 1) % 4]][j + jj[(dir + 1) % 4]] != -1)
                {
                    ans[i][j]=cnt++;
                    return ans;
                }
                dir++;
                dir %= 4;
            }
            //可以走
            else
            {
                ans[i][j]=cnt++;
                if(cnt==nn+1)
                {
                    return ans;
                }
                i += ii[dir % 4], j += jj[dir % 4];
            }
        }
    }
};
int main()
{
    Solution a;
    vector<vector<int>> arr=a.generateMatrix(10);
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
}