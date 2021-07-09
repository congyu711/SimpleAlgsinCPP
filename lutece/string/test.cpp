#include<bits/stdc++.h>
using namespace std;
bool equal(set<char> &a,set<char> &b)
{
    if(a.size()!=b.size())  return false;
    for(auto ita=a.begin(),itb=b.begin();ita!=a.end();ita++,itb++)
    {
        if(*ita!=*itb)  return false;
    }
    return true;
}
int main()
{
    set<char> a,b;
    for(int i=1;i<=4;i++)   a.insert(char('a'+i));
    for(int i=4;i>=1;i--)   b.insert(char('a'+i));
    if(equal(a,b))  cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;
}