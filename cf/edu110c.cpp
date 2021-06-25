#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9+7;

void solve()
{
    string s;
    cin>>s;
    vector<int> dp(s.length()+2);
    int pos=0,cnt=0;
    for(int l=0,r=0;l<s.length()&&r<s.length();r++)
    {
        if(l==r&&r==0){
            dp[r]=1;
            if(s[r]=='?')
            {pos=-1;
            cnt=1;}
            continue;
        }
        if((s[r]=='0'&&s[r-1]=='1')||(s[r]=='1'&&s[r-1]=='0'))
        {
            dp[r]=r-l+1;
            continue;
        }
        if(s[r]!='?'&&s[r]==s[r-1])
        {
            l=r;
            dp[r]=r-l+1;
            cnt=0;pos=0;
            continue;
        }
        if(s[r]=='?'&&s[r-1]!='?')
        {
            dp[r]=r-l+1;
            pos=r-1;
            cnt=1;
            continue;
        }
        if(s[r]=='?'&&s[r-1]=='?')
        {
            cnt++;
            dp[r]=r-l+1;
            continue;
        }
        if(s[r]!='?'&&s[r-1]=='?')
        {
            if(pos==-1)
            {
                dp[r]=r-l+1;
                continue;
            }
            if(cnt%2==1)
            {
                if(s[pos]==s[r])
                {
                    dp[r]=r-l+1;
                    cnt=0;
                    pos=0;
                    continue;
                }
                else
                {
                    dp[r]=r-pos;
                    l=pos+1;
                    cnt=0;
                    pos=0;
                    continue;
                }
            }
            else
            {
                if(s[pos]!=s[r])
                {
                    dp[r]=r-l+1;
                    cnt=0;
                    pos=0;
                    continue;
                }
                else
                {
                    dp[r]=r-pos;
                    l=pos+1;
                    cnt=0;
                    pos=0;
                    continue;
                }
            }
        }
    }
    
    LL ans=0;
    for(int i=0;i<s.length();i++)   ans+=dp[i];
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
}