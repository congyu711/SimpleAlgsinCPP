#include"sge.h"
using namespace std;
double scalingfactor;
// ofstream fout("log.out");

//to be fix. camera should be moveable;
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
            vec3d op=t-cmr.pos;
            double veclen=getlen(cmr.dir);
            double projlen=dotprdt(cmr.dir,op)/veclen;
            vec3d op1=op*(veclen/projlen);
            vec3d id=op1-cmr.dir;
            
            // auto lambda=[&](double src,int bits) ->double{
            //     stringstream ss;double f;
            //     ss<<fixed<<setprecision(bits)<<src;
            //     ss>>f;
            //     return f;
            // };
            double  xx=round(cmr.snwidth/2-id.y*scalingfactor),yy=round(cmr.snheight/2-id.z*scalingfactor);

            tmp.setPoint(idx,sf::Vector2f(xx,yy));
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
    scalingfactor=200;


    //note that every triangle should be described using 
    //conterclockwise order(looking from outside)
    //this can identify inner or outer side of an object;
    object o;
    o.tricnt=4;
    tri u;
    //need fix
    //need an input function
    u.pts.push_back(vec3d(1,0,0)),u.pts.push_back(vec3d(1,1,0)),u.pts.push_back(vec3d(1,0,1)); o.tris.push_back(u); u.pts.clear();
    u.pts.push_back(vec3d(1,1,1)),u.pts.push_back(vec3d(1,1,0)),u.pts.push_back(vec3d(1,0,1)); o.tris.push_back(u); u.pts.clear();
    u.pts.push_back(vec3d(1,1,1)),u.pts.push_back(vec3d(0,0,1)),u.pts.push_back(vec3d(1,0,1)); o.tris.push_back(u); u.pts.clear();
    u.pts.push_back(vec3d(1,1,1)),u.pts.push_back(vec3d(0,0,1)),u.pts.push_back(vec3d(0,1,1)); o.tris.push_back(u); u.pts.clear();
    u.pts.push_back(vec3d(1,1,1)),u.pts.push_back(vec3d(0,1,1)),u.pts.push_back(vec3d(1,1,0)); o.tris.push_back(u); u.pts.clear();
    u.pts.push_back(vec3d(1,0,0)),u.pts.push_back(vec3d(1,0,1)),u.pts.push_back(vec3d(0,0,1)); o.tris.push_back(u); u.pts.clear();

    
    double rotate_angle=0;
    sf::ContextSettings settings;
    settings.antialiasingLevel=0;
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
        }
        window.clear();

       

        sf::ConvexShape tmp;tmp.setPointCount(3);
        tmp.setFillColor(sf::Color::Transparent);
        tmp.setOutlineColor(sf::Color::Red);
        tmp.setOutlineThickness(-1);
        tmp.setPoint(0,sf::Vector2f(100,100));
        tmp.setPoint(1,sf::Vector2f(100,200));
        tmp.setPoint(2,sf::Vector2f(100,300));
        window.draw(tmp);
        //get fps
        frms++;
        if(frms>500) frms=0,start=chrono::steady_clock::now();
        auto nw=chrono::steady_clock::now();
        chrono::duration<double> eps_sec=nw-start;
        fps=(int)round((double)frms/eps_sec.count());
        sf::Text t(to_string(fps),font,30);
        t.setColor(sf::Color::Green);
        t.setPosition(0,0);
        window.draw(t);



        window.display();
    }
    return 0;
}
/*compile
cd "/home/congyu/wsl2_cpp/lutece/math/SimpleGraphicsEngine" && g++ test.cpp -o test -lsfml-window -lsfml-graphics -lsfml-system && ./test
*/