#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9+7;
LL a[N];
int n;
int bi[40],bii[40];
void solve()
{
    cin>>n;
    int c1=0,c2=0;
    for(int i=1;i<=n;i++)   cin>>a[i];
    vector<int> ans;
    ans.push_back(0);
    for(int ii=1;ii<n;ii++)
    {
        memset(bi,0,sizeof(bi));
        memset(bii,0,sizeof(bii));
        c1=0,c2=0;
        int c=a[ii];
        while(c)
        {
            bi[c1++]=c%2;
            c/=2;
        }
        c=a[ii+1];
        while(c)
        {
            bii[c2++]=c%2;
            c/=2;
        }

        // cout<<"bi ";
        // for(int i=0;i<c1;i++)   cout<<bi[i];
        // cout<<endl;
        // cout<<"bii";
        // for(int i=0;i<c2;i++)   cout<<bii[i];
        // cout<<endl;

        int tmp=0;
        for(int i=0;i<max(c1,c2);i++)
        {
            if(bi[i]==1&&bii[i]==0)
            {
                tmp+=(1<<i);
            }
        }
        a[ii+1]=(a[ii+1]^tmp);
        ans.push_back(tmp);
    }
    for(auto e:ans) cout<<e<<' ';
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
        solve();
}

/*
1
4
1 2 4 8
*/