#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==0)
            {
                flag=1;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(!matrix[i][j])
                {
                    matrix[0][j]=matrix[i][0]=0;
                }
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<m;j++)
            {
                if(!matrix[i][0]||!matrix[0][j])
                    matrix[i][j]=0;
            }
        }
        if(flag)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][0]=0;
            }
        }
        return ;
    }
};
int main()
{
    Solution a;

}