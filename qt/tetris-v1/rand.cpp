#include"rand.h"
#include<ctime>
#include<cstdlib>
#include<iostream>

Rand::Rand(){
    srand(unsigned(time(0)));
}

int Rand::randNum(const int &ax,const int &ay){
    int randNum;
    //randNum=ax+rand()%(ay-ax);//然而并不能产生闭区间的随机数 没有软用。
    double random(const double&,const double&);
    randNum=int(random(ax,ay));
    return randNum;
}

double random(const double &begin,const double &end){
    return begin+(end-begin)*rand()/(RAND_MAX+0.0);
}
