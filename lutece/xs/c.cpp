#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int prime[N/2],cnt=0;
vector<bool> check(N);
int n=N;
int t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=2;i<=n;i++)
    {
        if(!check[i])prime[cnt++]=i;
        for(int j=0;j<cnt&&prime[j]*i<=n;j++)
        {
            check[i*prime[j]]=1;
            if(!i%prime[j]) break;
        }
    }

    cin>>t;
    while(t--)
    {
        int ccc;
        cin>>ccc;
        int pos=upper_bound(prime,prime+cnt,ccc)-prime-1;
        cout<<prime[pos]*2<<endl;
    }
}
