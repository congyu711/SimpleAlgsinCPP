#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long LL;
LL dp[5010][1010];
string a,b;
string str1=" ",str2=" ";
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a;
    cin>>b;
    str1+=a;str2+=b;
    dp[0][0]=1;
    int n=str1.length()-1,m=str2.length()-1;
    for(int i=1;i<=n;i++)   dp[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i]==str2[j])
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                dp[i][j]%=mod;
            }
            else
            {
                dp[i][j]=dp[i-1][j];
                dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[n][m]%mod<<endl;
}