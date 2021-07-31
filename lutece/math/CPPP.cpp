//Closest Pair of Points on a Plane
#include<bits/stdc++.h>
using namespace std;
const double E=1e8;
class point
{
public:
    double x,y;
    point(double a,double b):x(a),y(b){}
    point():x(0),y(0){}
};
vector<point> arr;
double dis(const point &a,const point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void bf()
{
    double res=E;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            res=min(res,dis(arr[i],arr[j]));
        }
    }
    cout<<"brute-force ans: "<<res<<endl;
}
bool cmpx(const point &a,const point &b)
{
    if(a.x==b.x)    return a.y<b.y;
    return a.x<b.x;
}
bool cmpy(const point &a,const point &b)
{
    return a.y<b.y;
}
//O(nlogn) sol
double ans=E;
void updans(const point &a,const point &b)
{
    ans=min(dis(a,b),ans);
}
void solve(int l,int r)
{
    if(r-l<=3)
    {
        for(int i=l;i<=r;i++)
            for(int j=i+1;j<=r;j++)
                updans(arr[i],arr[j]);
        return;
    }
    int mid=l+r>>1;
    double mx=arr[mid].x;
    solve(l,mid);solve(mid+1,r);
    static point t[100];
    merge(arr.begin()+l,arr.begin()+mid+1,
    arr.begin()+mid+1,arr.begin()+r+1,t,cmpy);
    copy(t,t+r-l+1,arr.begin()+l);
    int tsz=0;
    for(int i=l;i<=r;i++)
    {
        if(fabs(arr[i].x-mx)<ans)
        {
            for(int j=tsz-1;j>=0&&arr[i].y-t[j].y;j--)
            {
                updans(arr[i],t[j]);
            }
            t[++tsz]=arr[i];
        }
    }
}

void dc()
{
    sort(arr.begin(),arr.end(),cmpx);
    int n=arr.size();
    solve(0,n-1);
    cout<<ans<<endl;
}
int main()
{
    const int pointnub=10;
    mt19937 gen(time(nullptr));
    for(int i=1;i<=pointnub;i++)
        arr.push_back(point(double(gen())/E,double(gen())/E));
    bf();
    dc();
}