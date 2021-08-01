#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countdist(int x,int y,int a,int b)
    {
        return ((x-a)*(x-a)+(y-b)*(y-b));
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(),0);
        for(int i=0;i<points.size();i++)
        {
            for(int j=0;j<queries.size();j++)
            {
                if(countdist(points[i][0],points[i][1],queries[j][0],queries[j][1])<=queries[j][2]*queries[j][2])
                    ans[j]++;
            }
        }
        return ans;
    }
};
int main()
{

}