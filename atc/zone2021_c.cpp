//https://atcoder.jp/contests/zone2021/tasks/zone2021_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool chk(vector<vector<int>> &arr, int mid)
{
    int n=arr.size();
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int c=0;
        for (int j = 0; j < 5; j++)
        {
            int bit=0;
            if(arr[i][j]>=mid) bit=1;
            c+=(bit<<j);
        }
        st.insert(c);
    }
    for(auto e:st)
        for(auto f:st)
            for(auto g:st)
            {
                if((e|f|g)==31)
                    return 1;
            }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(5, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];
    }

    int l = 1, r = 1e9 + 1;
    while (l < r)
    {
        int mid = (l + r)/2;
        if(chk(arr,mid))    l=mid+1;
        else r=mid;
    }
    cout<<l-1<<endl;
}
