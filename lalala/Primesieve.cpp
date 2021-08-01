#include <bits/stdc++.h>
using namespace std;
int prime[20010],check[200010],cnt=0;
int n=1000;
int main()
{
    for(int i=2;i<=n;i++)
    {
        if(!check[i])prime[cnt++]=i;
        for(int j=0;j<cnt&&prime[j]*i<=n;j++)
        {
            check[i*prime[j]]=1;
            if(!i%prime[j]) break;
        }
    }
    for(int i=0;i<cnt;i++)  cout<<prime[i]<<',';
    cout<<cnt<<endl;
}