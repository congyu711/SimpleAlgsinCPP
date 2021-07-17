#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;



void solve()
{
    int a[3],b[3],c[3],d[3];
    cin>>a[1]>>b[1]>>a[2]>>b[2];
    cin>>c[1]>>d[1]>>c[2]>>d[2];
    int cnt=0;
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=2;j++)
        {
            if(a[i]>=c[1]&&a[i]<=c[2]&&b[j]>=d[1]&&b[j]<=d[2])  cnt++;
        }
    }
    int cnt2=0;
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=2;j++)
        {
            if(c[i]>=a[1]&&c[i]<=a[2]&&d[j]>=b[1]&&d[j]<=b[2])  cnt2++;
        }
    }
    cnt=max(cnt,cnt2);
    // cout<<"cnt"<<cnt<<endl;
    if(a[1]==c[1]&&a[2]==c[2]&&d[1]==b[1]&&d[2]==b[2])
    {
        cout<<2<<endl;
        return;
    }
    if(cnt==4)
    {
        if(b[1]==d[1]&&b[2]==d[2]&&((c[1]>a[1]&&c[2]<a[2])||(c[1]<a[1]&&c[2]>a[2])))
        {
            cout<<4<<endl;
            return;
        }
        if(a[1]==c[1]&&a[2]==c[2]&&((d[1]>a[1]&&d[2]<a[2])||(d[1]<a[1]&&d[2]>a[2])))
        {
            cout<<4<<endl;
            return;
        }
        cout<<3<<endl;
        return;
    }
    if(cnt==2)
    {
        if(a[1]==c[2]||c[1]==a[2]||b[1]==d[2]||d[1]==b[2])
        {
            cout<<3<<endl;
            return;
        }
        //ab在cd里面
        if(a[1]>c[1]&&a[2]<c[2]&&d[1]==b[1]&&b[2]>d[2])
        {
            cout<<5<<endl;
            return;
        }
        if(a[1]>c[1]&&a[2]<c[2]&&d[2]==b[2]&&b[1]<d[1])
        {
            cout<<5<<endl;
            return;
        }
        for(int i=1;i<=2;i++)
            swap(a[i],c[i]),swap(b[i],d[i]);
        if(a[1]>c[1]&&a[2]<c[2]&&d[1]==b[1]&&b[2]>d[2])
        {
            cout<<5<<endl;
            return;
        }
        if(a[1]>c[1]&&a[2]<c[2]&&d[2]==b[2]&&b[1]<d[1])
        {
            cout<<5<<endl;
            return;
        }
        for(int i=1;i<=2;i++)
            swap(a[i],b[i]),swap(c[i],d[i]);
        if(a[1]>c[1]&&a[2]<c[2]&&d[1]==b[1]&&b[2]>d[2])
        {
            cout<<5<<endl;
            return;
        }
        if(a[1]>c[1]&&a[2]<c[2]&&d[2]==b[2]&&b[1]<d[1])
        {
            cout<<5<<endl;
            return;
        }
        for(int i=1;i<=2;i++)
            swap(a[i],c[i]),swap(b[i],d[i]);
        if(a[1]>c[1]&&a[2]<c[2]&&d[1]==b[1]&&b[2]>d[2])
        {
            cout<<5<<endl;
            return;
        }
        if(a[1]>c[1]&&a[2]<c[2]&&d[2]==b[2]&&b[1]<d[1])
        {
            cout<<5<<endl;
            return;
        }
        cout<<4<<endl;
        return;
        
    }
    if(cnt==1)
    {
        if(a[1]==c[2]&&c[1]<a[2])
        {
            cout<<3<<endl;
            return;
        }
        if(c[1]==a[2]&&a[1]<c[2])
        {
            cout<<3<<endl;
            return;
        }
        if(b[1]==d[2]&&d[1]<b[2])
        {
            cout<<3<<endl;
            return;
        }
        if(d[1]==b[2]&&b[1]<d[2])
        {
            cout<<3<<endl;
            return;
        }
        cout<<4<<endl;
        return;
    }
    if(cnt==0)
    {
        if(a[1]>c[2]||a[2]<c[1]||b[1]>d[2]||b[2]<d[1])
        {
            cout<<3<<endl;
            return;
        }
        else
        {
            cout<<6<<endl;
            return;
        }
    }
    // cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
        solve();
}

/*
1
0 0 3 3
1 0 2 4

*/