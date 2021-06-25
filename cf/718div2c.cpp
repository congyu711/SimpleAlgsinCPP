//
#include<bits/stdc++.h>
using namespace std;

int arr[501][501];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i][i];
        int a=i,b=i;
        int c=arr[i][i];
        for(int j=1;j<arr[i][i];j++)
        {
            if((b-1)!=0&&arr[a][b-1]==0)
            {
                b--;
                arr[a][b]=c;
            }
            else
            {
                a++;
                arr[a][b]=c;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
}
