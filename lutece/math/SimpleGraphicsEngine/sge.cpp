#include"sge.h"
using namespace std;
double scalingfactor;
// ofstream fout("log.out");
ifstream fin("objinfo.in");
///////////////////////////////////////////////////////////////////////////////////////////////
////////////    old version(using cmr.dir)
// void perspectiveprojection(vector<sf::ConvexShape> &vec,const object &obj,const camera &cmr)
// {
//     vec.clear();
//     for(auto tria:obj.tris)
//     {
//         sf::ConvexShape tmp;tmp.setPointCount(3);
//         tmp.setFillColor(sf::Color::Transparent);
//         tmp.setOutlineColor(sf::Color::Red);
//         tmp.setOutlineThickness(-1);
//         for(int idx=0;idx<3;idx++)
//         {
//             auto t=tria.pts[idx];
//             vec3d op=t-cmr.pos;
//             double veclen=getlen(cmr.dir);
//             double projlen=dotprdt(cmr.dir,op)/veclen;
//             vec3d op1=op*(veclen/projlen);
//             vec3d id=op1-cmr.dir;
            
//             // auto lambda=[&](double src,int bits) ->double{
//             //     stringstream ss;double f;
//             //     ss<<fixed<<setprecision(bits)<<src;
//             //     ss>>f;
//             //     return f;
//             // };
//             double  xx=round(cmr.snwidth/2-id.y*scalingfactor),yy=round(cmr.snheight/2-id.z*scalingfactor);

//             tmp.setPoint(idx,sf::Vector2f(xx,yy));
//         }
//         vec.push_back(tmp);
//     }
// }
/////////////////////////////////////////////////////////////////////////////////////////////////////////


////////    new version(using eular angle)
void perspectiveprojection(vector<sf::ConvexShape> &vec,const object &obj,const camera &cmr)
{
    vec.clear();
    for(auto tria:obj.tris)
    {
        sf::ConvexShape tmp;tmp.setPointCount(3);
        tmp.setFillColor(sf::Color::Transparent);
        tmp.setOutlineColor(sf::Color::Red);
        tmp.setOutlineThickness(-1);
        for(int idx=0;idx<3;idx++)
        {
            auto t=tria.pts[idx];
            vec3d ca=t-cmr.pos;
            vec3d d;
            auto r=cmr.rotateangle;
            d.x=cos(r.y)*sin(r.z)*ca.y+cos(r.y)*cos(r.z)*ca.x-sin(r.y)*ca.z;
            d.y=sin(r.x)*(cos(r.y)*ca.z+sin(r.y)*(sin(r.z)*ca.y+cos(r.z)*ca.x))+cos(r.x)*(cos(r.z)*ca.y-sin(r.z)*ca.x);
            d.z=cos(r.x)*(cos(r.y)*ca.z+sin(r.y)*(sin(r.z)*ca.y+cos(r.z)*ca.x))-sin(r.x)*(cos(r.z)*ca.y-sin(r.z)*ca.x);
            tmp.setPoint(idx,sf::Vector2f(round(-d.y*scalingfactor)+cmr.snwidth/2,round(-d.x*scalingfactor)+cmr.snheight/2));
        }
        vec.push_back(tmp);
    }
}
int main()
{

    camera cmr;
    cmr.snheight=720;
    cmr.snwidth=1280;
    cmr.pos=vec3d(-2.4,0,0);
    cmr.dir=vec3d(1,0,0);
    cmr.dirlen=getlen(cmr.dir);
    cmr.rotateangle=vec3d(0,pi/2.2,0);
    scalingfactor=200;


    //note that every triangle should be described using 
    //conterclockwise order(looking from outside)
    //this can identify inner or outer side of an object;
    object o;
    o.readObj(fin);
    
    double rotate_angle=0;
    sf::ContextSettings settings;
    settings.antialiasingLevel=8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML windows",sf::Style::Default,settings);
    window.setFramerateLimit(60);
    int64_t frms=1,fps=0;
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/abyssinica/AbyssinicaSIL-Regular.ttf");

    //get start_time
    auto start=chrono::steady_clock::now();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                cmr.rotateangle.y-=0.1;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                cmr.rotateangle.y+=0.1;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                cmr.rotateangle.z+=0.1;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                cmr.rotateangle.z-=0.1;
        }
        

        rotate_angle=(pi/60);
        for(auto &triangle:o.tris)
        {
            for(auto &point:triangle.pts)
            {
                double __dis=(point.x*point.x+point.y*point.y);
                point.x=cos(rotate_angle)*point.x-sin(rotate_angle)*point.y;
                point.y=sin(rotate_angle)*point.x+cos(rotate_angle)*point.y;
                if((point.x*point.x+point.y*point.y)<1e-8)   continue;
                point.x=point.x*sqrt(__dis)/sqrt((point.x*point.x+point.y*point.y));
                point.y=point.y*sqrt(__dis)/sqrt((point.x*point.x+point.y*point.y));
            }
        }

        vector<sf::ConvexShape> vec;
        perspectiveprojection(vec,o,cmr);
        window.clear();
        //to be fix, 
        for(auto e:vec)
        {
            window.draw(e);
        }
        
        ///////////////////////////////////////////////
        //get fps
        frms++;
        if(frms>500) frms=0,start=chrono::steady_clock::now();
        auto nw=chrono::steady_clock::now();
        chrono::duration<double> eps_sec=nw-start;
        fps=(int)round((double)frms/eps_sec.count());
        sf::Text t(to_string(fps),font,30);
        t.setFillColor(sf::Color::Green);
        t.setPosition(0,0);
        window.draw(t);
        //////////////////////////////////////////////////


        window.display();
    }
    return 0;
}
/*compile
cd "/home/congyu/wsl2_cpp/lutece/math/SimpleGraphicsEngine" && g++ sge.cpp -o sge -lsfml-window -lsfml-graphics -lsfml-system && ./sge
*/