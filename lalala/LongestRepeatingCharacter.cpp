#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        vector<int> cnt(26,0);
        int ans=0,maxn=0,r=0;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                cnt[s[i-1]-'A']--;      //顺序滑窗要判断一下maxn用不用减少
            }
            while(r<n)
            {
                
                cnt[s[r]-'A']++;
                maxn=max(maxn,cnt[s[r]-'A']);
                if(r-i+1-maxn>k)    break;
                r++;
            }
            ans=max(ans,r-i);
        }
        return ans;
    }
};
int main()
{
    Solution aaa;
    string a="AABABBA";
    int k=1;
    cout<<((Solution*)NULL)->characterReplacement(a,k);
}