#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    if(s.length()%2==1){
        cout<<"NO"<<endl;
        return 0;
    }
    stack<char> st;
    int cntl=0,cntr=0;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]==')')   cntr++;
        else if(s[i]=='(')  cntl++;
        else 
        {
            if(cntr>cntl)   s[i]='(',cntl++;
            else s[i]=')',cntr++;
        }
    }
    //cout<<s<<endl;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')   st.push(s[i]);
        else
        {
            if(st.empty())
            {
                cout<<"NO"<<endl;
                return 0;
            }
            else 
            {
                st.pop();
            }
        }
    }
    cout<<"YES"<<endl;
}