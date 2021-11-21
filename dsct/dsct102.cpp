#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;
int a,ans,n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        pq.push(a);
    }
    while(pq.size()>=2)
    {
        int a=pq.top();pq.pop();
        int b=pq.top();pq.pop();
        ans+=(a+b);
        pq.push(a+b);
    }
    cout<<ans<<endl;
}