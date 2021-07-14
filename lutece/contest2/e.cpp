#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
bitset<N> st[55];
int m,n,a,b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        int t;
        cin>>t;
        for(int j=1;j<=t;j++)
        {
            cin>>a;
            st[i].set(a,1);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            bitset<N> tmp,tmp2;
            tmp=st[i]|st[j];
            tmp2=st[i]&st[j];
            if(st[i]==st[j])    continue;   
            // cout<<tmp.count()<<endl;
            if(tmp2.count()==0)
            {
                cout<<"impossible"<<endl;
                return 0;
            }
        }
    }
    cout<<"possible"<<endl;
}