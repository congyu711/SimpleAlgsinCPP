#include<bits/stdc++.h>
using namespace std;
string s;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    cin>>s;
    vector<int> vec[30];
    for(int i=0;i<n;i++)
    {
        vec[s[i]-'a'].push_back(i);
    }
    int r=n-1,l=0;
    for(l=0;l<n;l++)
    {
        int f=-1;
        for(int k=0;k<s[l]-'a';k++)
        {
            if(f!=-1)   break;
            while(!vec[k].empty()&&vec[k].back()>r) vec[k].pop_back();
            if(!vec[k].empty()&&vec[k].back()<=r&&vec[k].back()>l)
            {
                f=vec[k].back();
                vec[k].pop_back();
            }
        }
        if(f!=-1)
        {
            r=f;
            swap(s[l],s[r]);
        }
    }
    cout<<s<<endl;
}