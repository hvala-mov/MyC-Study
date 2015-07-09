#ifndef CUBEPOINT_H_
#define CUBEPOINT_H_
//#include<iostream>
#include"cur.h"
enum class Colors{
    CLEAR=0,
    BLACK=30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    DEEP_GREEN,
    WHITE
};
class CubePoint{
    private:
        Colors color;
        int x;
        int y;//每一个方格点有颜色属性，坐标属性
    public:
        CubePoint():color(Colors::CLEAR),x(0),y(0){}
        CubePoint(const Colors &ac,const int &ax,const int &ay):color(ac),x(ax),y(ay){}
        void setLocate(const int &ax,const int &ay){x=ax;y=ay;}
        void setColor(Colors c){color=c;}
        Colors getColor(){return color;}
        void getLocate(int &ax,int &ay){ax=x;ay=y;}
        void printPoint();
        void ereasePoint();
};

#endif
