#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL mod=998244353;
const LL inf = INTMAX_MAX;
LL dp[1010][2][2][2];
int t;
string a,b,c;
//sta 42    sta2 135
LL dfs(int pos,int pre1,int pre2,int sta,int sta2,int sta3,bool lim)
{
    if(pos==-1) return 1;
    if(!lim && dp[pos][sta][sta2][sta3]!=-1) return dp[pos][sta][sta2][sta3];
    int up=lim ? (c[pos]-'0') : 9;
    LL res=0;
    for(int i=0;i<=up;i++)
    {
        if(pre1==4 && i==2)continue;
        if(pre2==1&&pre1==3&&i==5) continue;
        res+=dfs(pos-1,i,pre1,i==4,i==1,i==3&&pre1==1,lim && i==(c[pos]-'0'));
        res%=mod;
    }
    if(!lim) dp[pos][sta][sta2][sta3]=res%mod;
    return res%mod;
}
void solve()
{
    a.clear(),b.clear(),c.clear();
    cin>>a>>b;
    LL na=0,nb=0,res=0;
    for(int i=0;i<a.length();i++)
    {
        na=na*10+a[i]-'0';
        na%=mod;
    }
    for(int i=0;i<b.length();i++)
    {
        nb=nb*10+b[i]-'0';
        nb%=mod;
    }
    res=nb-na+1LL;
    while(res<0)res+=mod;
    res%=mod;
    // cout<<"res"<<res<<endl;
    stack<char> st;
    for(int i=0;i<a.length();i++)   st.push(a[i]);
    while(!st.empty())
    {
        c+=st.top();
        st.pop();
    }
    // cout<<"A"<<c<<endl;
    LL ans1=dfs(c.length()-1,-1,-1,0,0,0,1);
    // cout<<ans1<<endl;
    c.clear();
    for(int i=0;i<b.length();i++)   st.push(b[i]);
    while(!st.empty())
    {
        c+=st.top();
        st.pop();
    }

    // cout<<"B"<<c<<endl;
    LL ans2=dfs(c.length()-1,-1,-1,0,0,0,1);
    // cout<<ans2<<endl;
    LL fans=ans2-ans1;
    fans=(res-fans);
    // cout<<fans<<endl;
    //特判l
    bool f=0;
    for(int i=0;i<a.length();i++)
    {
        if(i>=1&&a[i]=='2'&&a[i-1]=='4')
        {
            f=1;
            break;
        }
        if(i>=2&&a[i]=='5'&&a[i-1]=='3'&&a[i-2]=='1')
        {
            f=1;
            break;
        }
    }
    if(!f)  fans-=1;
    while(fans<0)   fans+=mod;
    fans%=mod;
    cout<<fans<<endl;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
        solve();
}