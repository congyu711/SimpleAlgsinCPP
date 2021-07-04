#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const char *fin[5] =   {"11111",
                        "01111",
                        "00*11",
                        "00001",
                        "00000"};
char g[5][5];
const int dx[8]={1,1,2,2,-1,-1,-2,-2};
const int dy[8]={2,-2,1,-1,2,-2,1,-1};
int diff,limit,sx,sy;

#ifdef CONGYU
    ifstream infile("testcase.in");
#endif
void dfs(int x,int y,int dep,int fax,int fay)
{
    if(diff==0||dep==limit) return;
    if(diff>(limit-dep)+1)  return;
    for(int i=0;i<8;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<0||xx>4||yy<0||yy>4)  continue;
        if(xx==fax&&yy==fay)    continue;
        int tmp=diff;
        if(g[x][y]==fin[x][y])      diff++;
        if(g[xx][yy]==fin[xx][yy])  diff++;
        if(g[x][y]==fin[xx][yy])    diff--;
        if(g[xx][yy]==fin[x][y])    diff--;
        swap(g[xx][yy],g[x][y]);
        //cout<<x+1<<y+1<<' '<<xx+1<<yy+1<<' '<<dep<<limit<<' '<<diff<<endl;

        if(diff==0) return;
        if(diff>(limit-dep)+1){diff=tmp;swap(g[xx][yy],g[x][y]);continue;}
        dfs(xx,yy,dep+1,x,y);
        if(diff==0) return;
        diff=tmp;swap(g[xx][yy],g[x][y]);
    }
}
void solve()
{
    diff=0,limit=1;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>g[i][j];
            if(g[i][j]!=fin[i][j])  diff++;
            if(g[i][j]=='*')    sx=i,sy=j;
        }
    }
    //cout<<diff<<endl;
    if(diff==0) {cout<<0<<endl;return;}
    for(;limit<=15;limit++)
    {
        dfs(sx,sy,0,-1,-1);
        if(diff==0){cout<<limit<<endl;return;}
    }
    cout<<-1<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
}