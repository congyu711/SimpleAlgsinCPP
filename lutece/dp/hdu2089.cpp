#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL mod=998244353;
const LL inf = INTMAX_MAX;
int a[20];
int dp[20][2];

LL dfs(int pos,int pre,int sta,bool lim)
{
    if(pos==-1) return 1;
    if(!lim&&dp[pos][sta]!=-1)  return dp[pos][sta];
    int upb=lim?a[pos]:9;
    LL res=0;
    for(int i=0;i<=upb;i++)
    {
        if(pre==6&&i==2)continue;
        if(i==4)    continue;
        res+=dfs(pos-1,i,i==6,lim&&i==a[pos]);
    }
    if(!lim) dp[pos][sta]=res;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    LL l,r;
    while(cin>>l>>r&&l+r)
    {
        int pos=0;
        l--;
        while(l)
        {
            a[pos++]=l%10;
            l/=10;
        }
        LL cnt1=dfs(pos-1,-1,0,1);
        pos=0;
        memset(a,0,sizeof(a));
        while(r)
        {
            a[pos++]=r%10;
            r/=10;
        }
        LL cnt2=dfs(pos-1,-1,0,1);
        cout<<cnt2<<endl;
        cout<<cnt1<<endl;
    }
}