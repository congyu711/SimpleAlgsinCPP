#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 1e6 + 10;
const LL maxn = 1e16;
LL n, k, s, ans, mid;
LL a[30];
vector<LL> f;//存阶乘
vector<map<LL,LL> > mpl(30),mpr(30);
vector<set<LL> > stl(30);
void dfsl(int idx,int ed,LL sum,int cnt)
{
    if(idx>ed+1)  return;
    if(cnt==k+1)  return;
    if(sum>s)   return;
    //cout<<sum<<endl;
    dfsl(idx+1,ed,sum,cnt);
    if(idx<=ed)
    {
        if(cnt<k&&a[idx]<=18&&sum+f[a[idx]]<=s)
        {dfsl(idx+1,ed,sum+f[a[idx]],cnt+1);
        mpl[cnt+1][sum+f[a[idx]]]++,stl[cnt+1].insert(sum+f[a[idx]]);}
        if(sum+a[idx]<=s)
        {dfsl(idx+1,ed,sum+a[idx],cnt);
        mpl[cnt][sum+a[idx]]++,stl[cnt].insert(sum+a[idx]);}  
    }
}
void dfsr(int idx,int ed,LL sum,int cnt)
{
    if(idx>ed+1)  return;
    if(cnt==k+1)  return;
    if(sum>s)   return;
    
    //cout<<sum<<endl;
    dfsr(idx+1,ed,sum,cnt);
    if(idx<=ed)
    {
        if(cnt<k&&a[idx]<=18&&sum+f[a[idx]]<=s)
        {dfsr(idx+1,ed,sum+f[a[idx]],cnt+1);
        mpr[cnt+1][sum+f[a[idx]]]++;}
        if(sum+a[idx]<=s)
        {dfsr(idx+1,ed,sum+a[idx],cnt);
        mpr[cnt][sum+a[idx]]++;}  
    }
}
int main()
{
    #ifndef CONGYU
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    #endif
    #ifdef CONGYU
        ifstream cin("testcase.in");
    #endif

    f.push_back(1);
    while (1)
    {
        LL c = f.size(), pre = f[c - 1];
        if (c * pre >= maxn)
            break;
        f.push_back(c * pre);
    }
    cin>>n>>k>>s;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    mid=n/2;
    dfsl(1,mid,0,0);
    dfsr(mid+1,n,0,0);
    stl[0].insert(0);
    for(int i=0;i<=k;i++)
    {
        mpl[i][0]=mpr[i][0]=1;

        int rm=k-i;
        for(auto e:stl[i])
        {
            LL c=s-e;
            LL ans1=mpl[i][e];
            
            LL ans2=0;
            for(int j=0;j<=rm;j++)
            {
                if(mpr[j][c]>0) ans2+=mpr[j][c];
                //cout<<mpr[j][c]<<' '<<c<<endl;
            }
            //cout<<"左边的数，左边有几个，i "<<e<<' '<<ans1<<' '<<ans2<<' '<<i<<endl;
            ans+=(ans1*ans2);
            //cout<<e<<' ';
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
}