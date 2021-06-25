#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int arr[N];
vector<int> vec[N];
int n,a,b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
}