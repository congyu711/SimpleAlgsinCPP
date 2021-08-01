#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,0);
        if(s.length()==0||(s.length()==1&&s[0]=='0'))   return 0;
        if(s.length()==1)   return 1;
        dp[0]=1;
        dp[1]=s[0]!='0';
        for(int i=2;i<=s.length();i++)
        {
            if(s[i-2]!='0'&&stoi(s.substr(i-2,2))<26)   dp[i]+=dp[i-2];
            if(s[i-1]!='0') dp[i]+=dp[i-1];
        }
        for(auto e:dp)  cout<<e<<endl;
        return dp[s.length()];
    }
};
int main()
{
    string a="12";
    Solution so;
    so.numDecodings(a);
    //cout<<so.numDecodings(a)<<endl;
}