#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[20][20];
int n;
bool l[20];
vector<pair<int,int>> arr;
int ans;
int solve()
{
    int res=0;
    if(arr.size()==n)
    {
        for(auto e:arr)
            res^=(a[e.first][e.second]);
        return res;
    }
    int j;
    for(int i=1;i<=2*n;i++)
        if(!l[i])
        {
            j=i;
            l[i]=1;
            break;
        }
    for(int i=1;i<=2*n;i++)
    {
        if(!l[i])
        {
            l[i]=1;
            arr.push_back(make_pair(j,i));
            res=max(res,solve());
            l[i]=0;
            arr.pop_back();
        }
    }


    l[j]=0;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < 2 * n; i++)
    {
        for (int j = i + 1; j <= 2 * n; j++)
        {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    
    cout << solve() << endl;
}