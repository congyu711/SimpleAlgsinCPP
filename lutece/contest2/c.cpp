#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
int arr[N][10];
int n,m;

bool chk(int mid)
{
    set<int> st;
    for(int i=1;i<=n;i++)
    {
        int c=0;
        for(int j=1;j<=m;j++)
        {
            int bit=0;
            if(arr[i][j]>=mid)  bit=1;
            c+=(bit<<(j-1));
        }
        st.insert(c);
    }
    for(auto &e:st)
        for(auto &f:st)
            if((e|f)==((1<<m)-1))   return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        int res=0x7fffffff;
        for(int j=1;j<=m;j++)
        {
            res=min(arr[i][j],res);
        }
        ans=max(ans,res);
    }
    int l = 1, r = 1e9 + 1;
    while (l < r)
    {
        int mid = (l + r)/2;
        if(chk(mid))    l=mid+1;
        else r=mid;
    }
    cout<<max(ans,l-1)<<endl;
}