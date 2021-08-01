//3_15 beat 100% c++ users!!!
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int i = 0, j = 0;
        int ii[4] = {0, 1, 0, -1};
        int jj[4] = {1, 0, -1, 0};
        int dir = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        if (m == 1)
        {
            for (int i = 0; i < n; i++)
                ans.push_back(matrix[0][i]);
            return ans;
        }
        else if (n == 1)
        {
            for (int i = 0; i < m; i++)
                ans.push_back(matrix[i][0]);
            return ans;
        }

        while (1)
        {
            //越界
            if (i + ii[dir % 4] >= m || i + ii[dir % 4] < 0 ||
                j + jj[dir % 4] < 0 || j + jj[dir % 4] >= n)
            {
                dir++;
                dir %= 4;
            }
            //已经跑过
            else if (matrix[i + ii[dir % 4]][j + jj[dir % 4]] == 0)
            {
                if (matrix[i + ii[(dir + 1) % 4]][j + jj[(dir + 1) % 4]] == 0)
                {
                    ans.push_back(matrix[i][j]);
                    break;
                }
                dir++;
                dir %= 4;
            }
            //可以走
            else
            {
                ans.push_back(matrix[i][j]);
                matrix[i][j] = 0;

                i += ii[dir % 4], j += jj[dir % 4];
            }
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> input = {{1},{2}};
    Solution a;
    auto res = a.spiralOrder(input);
    for (auto e : res)
    {
        cout << e << ' ';
    }
}