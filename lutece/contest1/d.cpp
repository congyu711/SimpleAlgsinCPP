#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e5+10;
LL lowbit(LL x){return x&-x;}
LL tree[N<<2];
LL arr[N];
LL n;
void add(int id,int x)
{
    for(int i=id;i<=n;i+=lowbit(i))
        tree[i]+=x;
}
LL query(LL x)
{
    LL res=0;
    for(int i=x;i>0;i-=lowbit(i))
        res+=tree[i];
    return res;
}


void solve()
{
    memset(arr,0,sizeof(arr));
    memset(tree,0,sizeof(tree));
    cin>>n;
    LL v=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        add(arr[i],1);
        v+=i-query(arr[i]);
    }
    LL ans=v;
    int q;
    cin>>q;
    int l,r;
    while(q--)
    {
        cin>>l>>r;
        for(int i=l+1;i<r;i++)
        {
            if(arr[i]<arr[l])   v--;
            if(arr[i]>arr[l])   v++;
            if(arr[i]<arr[r])   v++;
            if(arr[i]>arr[r])   v--;
        }
        if(arr[r]>arr[l])   v++;
        else v--;
        ans=min(ans,v);
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    LL t;
    cin>>t;
    while(t--)  
        solve();
}