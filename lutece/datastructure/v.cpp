#include <bits/stdc++.h>
using namespace std;
int l,r;
int st[1000000][21];
//这都要卡、、、、、、
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int maxxxx(int l, int r)
{
    int k = log2(r - l + 1);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    n=read(),m=read();
    for (int i = 1; i <= n; i++)
        st[i][0]=read();
    for (int j = 1; j <= 21; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    for (int i = 1; i <= m; i++)
    {
        l=read(),r=read();
        printf("%d\n",maxxxx(l,r));
    }
}