#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& hs) {
        int n = hs.size(), res = 0, l = 0, r = n-1, lm = 0, rm = 0;
        while(l < r){
            lm = max(hs[l], lm), rm = max(hs[r], rm);
            if(hs[l] < hs[r])
                res += lm - hs[l++];
            else res += rm - hs[r--];
        }
        return res;
    }
};
int main()
{
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1}; //10
    Solution a;
    cout<<a.trap(arr);
}