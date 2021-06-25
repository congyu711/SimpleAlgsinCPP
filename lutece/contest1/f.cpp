#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;

void solve()
{
    int n, k;
    cin >> n >> k;
    getchar();
    string s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>s;
        int cnt=0;
        for(int j=0;j<s.length();j++)
        {
            if(s[j]=='/')   cnt++;
            if(cnt==4)
            {
                int res=0;
                for(int k=j+1;k<s.length();k++)
                    res=(res*10+(s[k]-'0'));
                arr[i]=res;
                break;
            }
        }
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < k; i++)
        cout << arr[i] << ' ';
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
/*
2
3 3
http://acm.uestc.edu.cn/problemset/3
http://acm.uestc.edu.cn/problemset/2
http://acm.uestc.edu.cn/problemset/1
4 3
http://acm.uestc.edu.cn/problemset/981
http://acm.uestc.edu.cn/problemset/379
http://acm.uestc.edu.cn/problemset/4865
http://acm.uestc.edu.cn/problemset/10000

*/