#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
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
    
}