//https://atcoder.jp/contests/zone2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque<char> dq;
    string s;
    cin >> s;
    int rev=0;
    for(auto c:s)
    {
        if(c=='R')  rev^=1;
        else if(rev)   dq.push_front(c);
        else dq.push_back(c);
    }
    if(rev) reverse(dq.begin(),dq.end());
    string ans;
    for(auto e:dq)
    {
        if(ans.size()&&ans.back()==e)   ans.pop_back();
        else ans.push_back(e);
    }
    cout<<ans<<endl;
}
