#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int n,d;
int s[10][10],t[10][10];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int r,c;
int diff;
bool fsh;


void dfs(int dep)
{
    if(diff==0) {fsh=1;return;}
    for(int k=0;k<4;k++)
    {
        if(fsh==1)  return;
        if((r+dx[k])<1||(r+dx[k])>n||(c+dy[k])<1||(c+dy[k])>n)  continue;
        r+=dx[k],c+=dy[k];
        int tmp[10][10];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                tmp[i][j]=s[i][j];
            }
        }
        int prediff=diff;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int cntnber=0;
                for(int a=i-1;a<=i+1;a++)
                {
                    for(int b=j-1;b<=j+1;b++)
                    {
                        if(i==a&&j==b)  continue;
                        if(a<1||a>n||b<1||b>n)  continue;
                        if(tmp[a][b]==1)    cntnber++;
                    }
                }
                if(i==r&&j==c)  s[i][j]=0;
                else if((cntnber==3||cntnber==2)&&tmp[i][j]==1) s[i][j]=1;
                else if(tmp[i][j]==0&&cntnber==3) s[i][j]=1;
                else s[i][j]=0;
            }
        }   
        diff=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i][j]!=t[i][j])    diff++;
            }
        }
        // if(diff==0) cout<<dep+1<<endl;
        if(diff==0) {fsh=1;return;}
        if(dep+1<d) dfs(dep+1);
        diff=prediff;
        r-=dx[k];c-=dy[k];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                s[i][j]=tmp[i][j];
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>d;
    cin>>r>>c;
    r++,c++;
    for(int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        for(int j=0;j<n;j++)
            s[i][j+1]=str[j]-'0';
    }
    for(int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        for(int j=0;j<n;j++)
            t[i][j+1]=str[j]-'0';
    }



    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i][j]!=t[i][j])    diff++;
        }
    }
    if(diff==0) fsh=1;
    dfs(0);
    if(fsh==1)  cout<<"Yes\n";
    else cout<<"No\n";
}