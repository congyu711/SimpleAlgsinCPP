#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;


int n,m;
LL ans;
void manacher(int L,int R,string &s)
{
    int n=R-L+1;
    vector<int> odd(n),even(n);
    for(int i=0,l=0,r=-1;i<n;i++)
    {
        int k=(i>r)?1:min(odd[l+r-i],r-i);
        while(i-k>=0&&i+k<n&&s[i-k+L]==s[i+k+L])    k++;
        odd[i]=k--;
        ans+=odd[i];
        if(i+k>r)
        {
            l=i-k;
            r=i+k;
        }
    }
    for(int i=0,l=0,r=-1;i<n;i++)
    {
        int k=(i>r)?0:min(even[l+r-i+1],r-i+1);
        while(i-k-1>=0&&i+k<n&&(s[i-k+L-1]==s[i+k+L]))    k++;
        even[i]=k--;
        ans+=even[i];
        if(i+k>r)
        {
            l=i-k-1;
            r=i+k;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    vector<vector<int> > g(n+2,vector<int> (m+2,0));
    
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<)
    }
}