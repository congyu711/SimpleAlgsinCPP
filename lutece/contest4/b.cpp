#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int m,n,k,t;
int a[N];
int l[N],r[N],d[N],chafen[N],qz[N];
vector<int> mk[N];
bool cmp(int x,int y)
{
    return x>y;
}
bool check(int mina)
{
    mina=a[mina];
    memset(chafen,0,sizeof(chafen));
    memset(qz,0,sizeof(qz));
    for(int i=1;i<=k;i++)
    {
        if(d[i]>mina)
        {
            chafen[l[i]]++;
            chafen[r[i]+1]--;
        }
    }
    for(int i=1;i<=n;i++)
    {
        qz[i]=qz[i-1]+chafen[i];
    }
    LL tm=n+1;
    for(int i=1;i<=n;i++)
    {
        LL tmp=0;
        while(i<=n&&qz[i]>0) i++,tmp++;
        tm+=(2*tmp);
    }
    // cout<<mina<<' '<<tm<<endl;
    if(tm<=t)    return 1;
    else return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>m>>n>>k>>t;
    for(int i=1;i<=m;i++)   cin>>a[i];
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=k;i++)
    {
        cin>>l[i]>>r[i]>>d[i];
    }
    int ll=0,rr=m+1,mid;
    while(ll+1<rr)
    {
        mid=ll+rr>>1;
        if(check(mid))
            ll=mid;
        else    rr=mid;
    }
    cout<<ll<<endl;
}