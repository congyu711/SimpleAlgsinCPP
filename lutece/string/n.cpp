#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 1e6 + 10;
LL a[50],s[50];
vector<LL> lhs,rhs;
LL n,t,ans,mid;
// void solve(LL k,LL sum)
// {
//     if(sum>t)  return ;
//     if(sum+s[n]-s[k-1]<=ans) return;
//     if(k==n+1)    {ans=max(ans,sum);return;}
//     if(ans==t)  return;
//     solve(k+1,sum+a[k]);
//     solve(k+1,sum);
// }
// bool cmp(LL a,LL b){return a>b;}

void pls(int i,LL sum)
{
    if(sum>t)   return;
    lhs.push_back(sum);
    if(i==mid+1)    {return;}
    pls(i+1,sum+a[i]);
    pls(i+1,sum);
}
void prs(int i,LL sum)
{
    if(sum>t)   return;
    rhs.push_back(-sum);
    if(i==n+1)    {return;}
    prs(i+1,sum+a[i]);
    prs(i+1,sum);
}
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef CONGYU
    ifstream cin("testcase.in");
    #endif
    cin>>n>>t;
    for(int i=1;i<=n;i++)   cin>>a[i];
    // sort(a+1,a+n+1);
    // for(int i=1;i<=n;i++)   s[i]=s[i-1]+a[i];
    // if(s[n]<=t)
    // {
    //     cout<<s[n]<<endl;
    //     return 0;
    // }
    // solve(1,0);
    // cout<<ans<<endl;

    mid=n/2;//1--mid, mid+1--n;
    pls(1,0);prs(mid+1,0);
    sort(rhs.begin(),rhs.end());
    for(auto e:rhs)
    {
        if((-e)>t) break;
        ans=max(ans,-e);
    }
    for(auto e:lhs)
    {
        if(e>t) continue;
        ans=max(ans,e);
        LL c=t-e;
        auto it=lower_bound(rhs.begin(),rhs.end(),-c);
        if(it!=rhs.end())   ans=max(ans,e-(*it));
    }
    cout<<ans<<endl;
}