#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int g[5][5];
char c;
int fin[5][5]={{1,1,1,1,1},{0,1,1,1,1},{0,0,2,1,1},{0,0,0,1,1},{0,0,0,0,1}};
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef CONGYU
    ifstream cin("testcase.in");
    #endif
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>c;
            if(c=='*')  g[i][j]=2;
            else g[i][j]=c-'0';
        }
    }

}