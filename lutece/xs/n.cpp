#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int n,k;
int arr[N];
LL getans(int l,int r,int len)
{
    if(r-l<0)  return 0;
    if((r-l+1)==2)
    {
        // cout<<arr[r]<<' '<<arr[l]<<endl;
        return (arr[r]-arr[l])+2*len;
    }
    if((r-l+1)==1)
    {
        return len;
    }
    return (arr[r]-arr[l])+(r-l+1)*len+getans(l+1,r-1,arr[r]-arr[l]);
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    ifstream infile;
    infile.open("tc1.in");
    infile>>n>>k;

    for(int i=1;i<=n;i++)
        infile>>arr[i];
    sort(arr+1,arr+n+1);
    LL ans=0;
    int pos=k-1;
    //先算最外层
    ans+=arr[pos]-arr[1];
    // cout<<ans<<endl;
    ans+=getans(2,pos-1,arr[pos]-arr[1]);
    cout<<ans<<endl;
    for(int i=1;i<=pos;i++)
        ans+=(arr[n]-arr[i]);
    // cout<<ans<<endl;

    int res=0;
    for(int i=1;i<=pos;i++)
    {
        for(int j=i+1;j<=pos;j++)
            res+=abs(arr[j]-arr[i]);
    }
    cout<<"baoli"<<res<<endl;
}