#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
int arr[N<<1],idx[N<<1];
int n;
int chafen[N<<1];
int main()
{
    cin>>n;
    for(int i=1;i<=n*2;i++)
    {
        cin>>arr[i];
        ixd[i]=arr[i];
    }
    sort(idx+1,idx+n*2+1);
	int len=unique(idx+1,idx+n*2+1)-idx-1;
	for(int i=1;i<=n*2;i++)
		arr[i]=lower_bound(idx+1,idx+len+1,arr[i])-idx;
    
}