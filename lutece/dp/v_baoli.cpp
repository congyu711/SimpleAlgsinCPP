#include <bits/stdc++.h>
using namespace std;
const int N = 510;
typedef long long LL;
const LL inf = INTMAX_MAX;
int maxx=0;
int main()
{
    int n,k,ans=0;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)   arr[i]=i+1;
    do
    {
        int res=0;
        for(int i=0;i<n;i++)
        {
            res+=abs(arr[i]-(i+1));
        }
        if(res==k)  ans++;
        maxx=max(maxx,res);
    } while (next_permutation(arr.begin(),arr.end()));
    cout<<ans<<endl;
    cout<<maxx<<endl;
}