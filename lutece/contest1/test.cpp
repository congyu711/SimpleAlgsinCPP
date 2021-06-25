#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;

void solve()
{
    LL n, m;
    cin >> n >> m;
}
bool arr[200][200];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int a = 1; a * i <= n; a++)
            {
                for (int b = 1; b * j <= m; b++)
                {
                    arr[a * i][b * j] ^= 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout<<arr[i][j]<<' ';
        cout<<endl;
    }
}