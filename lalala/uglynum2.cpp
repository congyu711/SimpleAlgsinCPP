#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
       vector<int> ans;
       ans.push_back(1);
       for(int i=1,a=0,b=0,c=0;i<n;i++)
       {
           int aa=ans[a]*2,bb=ans[b]*3,cc=ans[c]*5;
           int minn=min(aa,min(bb,cc));
           if(minn==aa) a++;
           if(minn==bb) b++;
           if(minn==cc) c++;
           ans.push_back(minn);
       }
       return ans[n-1];
    }
};
int main()
{
    cout<<((Solution*)NULL)->nthUglyNumber(28);
}