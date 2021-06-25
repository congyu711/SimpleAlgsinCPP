#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
typedef long long LL;
class name
{
public:
    string a, b;
    int no;
};
bool cmp(name &aa, name &b)
{
    if (mp[aa.a] == mp[b.a])
        return aa.no < b.no;
    return mp[aa.a] > mp[b.a];
}
name arr[50010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // ifstream cin("tc1.in");
    int n=1;
    while(cin>>arr[n].a)
    {
        cin>>arr[n].b;
        // cin>>arr[n].a>>arr[n].b;
        n++;
        // if(cin.fail())  break;
    }
    n--;
    for (int i = 1; i <= n; i++)
        {mp[arr[i].a]++;arr[i].no=i;}
    sort(arr + 1, arr + n + 1, cmp);
    // cout<<n<<endl;
    for(int i=1;i<=n;i++)
        cout<<arr[i].a<<' '<<arr[i].b<<endl;
}