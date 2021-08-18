#pragma once
#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
using namespace std;
const double pi=acos(-1);
//def vector
class vec3d
{
public:
    double x,y,z;
    vec3d(){}
    vec3d(double a,double b,double c):
    x(a),y(b),z(c){}
    
};
vec3d operator-(const vec3d &a,const vec3d &b)
{
    vec3d res;
    res.x=a.x-b.x;
    res.y=a.y-b.y;
    res.z=a.z-b.z;
    return res;
}
vec3d operator+(const vec3d &a,const vec3d &b)
{
    vec3d res;
    res.x=a.x+b.x;
    res.y=a.y+b.y;
    res.z=a.z+b.z;
    return res;
}
vec3d operator*(const vec3d &a,const double f)
{
    vec3d res;
    res.x=a.x*f;
    res.y=a.y*f;
    res.z=a.z*f;
    return res;
}
vec3d operator*(const double f,const vec3d &a)
{
    vec3d res;
    res.x=a.x*f;
    res.y=a.y*f;
    res.z=a.z*f;
    return res;
}
double getlen(const vec3d& v)
{
    return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}
double dotprdt(const vec3d &v1,const vec3d &v2)
{
    return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}
vec3d crossprdt(const vec3d &v1,const vec3d &v2)
{
    vec3d res;
    res.x=v1.y*v2.z-v1.z*v2.y;
    res.y=v1.z*v2.x-v1.x*v2.z;
    res.z=v1.x*v2.y-v1.y*v2.x;
    return res;
}

//def camera and screen
class camera
{
public:
    vec3d pos; //camera pos (x,y,z)
    vec3d dir;  //direction. also length
    //i found that when i rotate the camera(actually the vector dir), there is always a flote eps
    //so if i rotate many times, the length of dir will become shorter.
    //haven't found a effective solution, so declear a new var(length of dir);
    double dirlen;

    //8.18
    //i found morden 3d graphic engines use Tait-Bryan_angles to describe camera direction
    //it's convenient to rotate...
    vec3d rotateangle;
    double angleV,angleH;
    double snwidth,snheight;//pixal
    //return pair<angleH，angleV>
    pair<double,double> getangle()
    {
        angleH=atan(snwidth / 2 / getlen(dir));
        angleV=atan(snheight / 2 / getlen(dir));
        return make_pair(angleH,angleV);
    }
};

class tri
{
public:
    vector<vec3d> pts;
    // int edgclr[3];//pts[0]-pts[1], pts[1]-pts[2], pts[2]-pts[0]
    // int innerclr;
};

class object
{
public:
    int tricnt;
    vector<tri> tris;
    void readObj(istream &is)
    {
        int n;
        is>>n;
        
        double a,b,c;
        for(int i=1;i<=n;i++)
        {
            tri tmptri;
            is>>a>>b>>c;
            tmptri.pts.push_back(vec3d(a,b,c));
            is>>a>>b>>c;
            tmptri.pts.push_back(vec3d(a,b,c));
            is>>a>>b>>c;
            tmptri.pts.push_back(vec3d(a,b,c));
            tricnt++;
            tris.push_back(tmptri);
        }
    }
};